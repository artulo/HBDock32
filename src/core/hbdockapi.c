#include <windows.h>

#include "hbdockapi.h"

#include "hbdockmanager.h"
#include "hbdockmanagerregister.h"
#include "hbdockmanagerfindpanel.h"
#include "hbdockmanagerdock.h"
#include "hbdockmanagerfloat.h"
#include "hbdockmanagerautohide.h"
#include "hbdockmanagerlayout.h"
#include "hbdockmanagerundock.h"
#include "hbdockmanagertabify.h"
#include "hbdockworkspace.h"
#include "hbdockhost.h"
#include "hbdocktheme.h"
#include "hbdockpaneldocksize.h"

/*
 * Nota de estabilizacion (Etapa 8): hbdockapi.h declara esta capa de
 * fachada (pensada para que el puente Harbour no tenga que conocer
 * HB_DOCK_MANAGER/HB_DOCK_PANEL directamente, solo punteros opacos
 * "void *" y nombres de panel como string) desde el principio del
 * proyecto -- pero NINGUNA de estas 10 funciones tenia implementacion
 * en ningun archivo. Los 8 HB_FUNC() existentes en src/harbour/ ya
 * llamaban a esta capa, asi que el puente Harbour completo estaba
 * roto de raiz (unresolved external en cuanto se linkeara cualquier
 * .exe que lo usara). Se implementa toda la fachada aqui, delegando
 * en las funciones reales de src/manager/ ya estabilizadas en las
 * Etapas 1 a 7.
 *
 * Mapeo de nSide/nGuide (Harbour pasa un entero): coincide 1 a 1 con
 * HB_DOCK_SITE / HB_DOCK_GUIDE_TYPE:
 *   0 = ninguno   1 = izquierda   2 = derecha
 *   3 = arriba    4 = abajo       5 = centro (tabifica)
 */

/*
 * Nota de estabilizacion: hbDockInitialize/hbDockFinalize se
 * eliminaron de esta fachada. Encontramos (via el .lib real armado
 * con BCC7.3) que YA existia una implementacion separada y anterior
 * en src/hbdock.c / include/hbdock.h -- el header "principal" del
 * proyecto (dice literalmente "Main Public Header", con control de
 * version 0.1.0 y compatibilidad Harbour 3.2 documentada), con
 * hbDockInitialize (con guarda estatica real) y hbDockExit. Definir
 * una segunda version aca era un simbolo duplicado esperando a
 * romper el enlazado del primer .exe real que se armara. El puente
 * Harbour (HBDockInitialize/HBDockFinalize) ahora llama directo a
 * las funciones de hbdock.h -- ver src/harbour/hbdockhbinit.c.
 */

void * hbDockCreateManager( HWND hMainWnd )
{
   HB_DOCK_MANAGER * pManager;

   if( hMainWnd == NULL )
      return NULL;

   pManager =
      ( HB_DOCK_MANAGER * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_MANAGER ) );

   if( pManager == NULL )
      return NULL;

   if( !hbDockManagerCreate(
            pManager,
            hMainWnd ) )
   {
      LocalFree(
         pManager );

      return NULL;
   }

   return ( void * ) pManager;
}

void hbDockDestroyManager( void * pManager )
{
   if( pManager == NULL )
      return;

   hbDockManagerDestroy(
      ( HB_DOCK_MANAGER * ) pManager );

   LocalFree(
      pManager );
}

BOOL hbDockRegisterPanel(
        void * pManager,
        HWND hPanel,
        LPCTSTR pszName,
        LPCTSTR pszCaption )
{
   if( pManager == NULL )
      return FALSE;

   return hbDockManagerRegisterPanel(
      ( HB_DOCK_MANAGER * ) pManager,
      hPanel,
      pszName,
      pszCaption );
}

BOOL hbDockDockPanel(
        void * pManager,
        LPCTSTR pszPanel,
        int nSide )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   return hbDockManagerDockPanel(
      pMgr,
      pPanel,
      ( HB_DOCK_GUIDE_TYPE ) nSide );
}

BOOL hbDockFloatPanel(
        void * pManager,
        LPCTSTR pszPanel )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;
   POINT pt;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   /* Sin una posicion de mouse real (esto no viene de un arrastre),
    * se flota junto a la esquina superior izquierda del rect actual
    * del panel. */
   pt.x = pPanel->Rect.left;
   pt.y = pPanel->Rect.top;

   hbDockManagerFloatPanel(
      pMgr,
      pPanel,
      pt );

   return TRUE;
}

/*
 * Etapa 49: fijar el ancho/alto deseado de un panel para cuando se
 * acople (ver hbDockLayoutInsertPanel) -- llamar ANTES de acoplarlo
 * (por ejemplo, antes del primer Dock() en ON INIT, o antes de un
 * Dock() posterior). cx se usa para LEFT/RIGHT, cy para TOP/BOTTOM;
 * pasar 0 en el que no aplique (o en ambos, para volver al 50/50
 * default).
 */
BOOL hbDockSetPanelSize(
        void * pManager,
        LPCTSTR pszPanel,
        int cx,
        int cy )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   hbDockPanelSetDockSize(
      pPanel,
      cx,
      cy );

   return TRUE;
}

/*
 * Etapa 64: pedido explicito -- acoplar un panel sin caption y sin
 * los botones de pin/cerrar, para usarlo como area central de
 * trabajo (tipo MDI) sin la barra de titulo de los demas paneles.
 */
BOOL hbDockSetPanelNoCaption(
        void * pManager,
        LPCTSTR pszPanel,
        BOOL bNoCaption )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   pPanel->NoCaption = bNoCaption ? 1 : 0;

   return TRUE;
}

/*
 * Etapa 80: pedido explicito -- temas visuales (Office 2007/2010/
 * 2015). Cambia el tema actual y fuerza un repintado completo de la
 * ventana principal (captions/tabs/autohide leen del tema en cada
 * pasada de pintado, asi que alcanza con invalidar todo).
 */
BOOL hbDockSetTheme(
        void * pManager,
        int nTheme )
{
   HB_DOCK_MANAGER * pMgr;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   if( nTheme < HBDOCK_THEME_OFFICE2007 ||
       nTheme > HBDOCK_THEME_OFFICE2015 )
      return FALSE;

   hbDockThemeSetCurrent(
      ( HB_DOCK_THEME_ID ) nTheme );

   if( pMgr->hMainWnd != NULL )
      RedrawWindow(
         pMgr->hMainWnd,
         NULL,
         NULL,
         RDW_INVALIDATE | RDW_ALLCHILDREN | RDW_UPDATENOW | RDW_ERASE );

   return TRUE;
}

BOOL hbDockAutoHidePanel(
        void * pManager,
        LPCTSTR pszPanel )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   hbDockManagerAutoHidePanel(
      pMgr,
      pPanel );

   return TRUE;
}

BOOL hbDockShowPanel(
        void * pManager,
        LPCTSTR pszPanel )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   pPanel->Visible = 1;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );

   hbDockManagerLayout(
      pMgr );

   return TRUE;
}

BOOL hbDockHidePanel(
        void * pManager,
        LPCTSTR pszPanel )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   pPanel->Visible = 0;

   if( pPanel->hWnd != NULL )
      ShowWindow(
         pPanel->hWnd,
         SW_HIDE );

   hbDockManagerLayout(
      pMgr );

   return TRUE;
}

BOOL hbDockUndockPanel(
        void * pManager,
        LPCTSTR pszPanel )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   if( pPanel->pContainer == NULL )
      return FALSE;

   /*
    * Nota de estabilizacion: esta fachada duplicaba la logica de
    * hbDockManagerUndock llamando directo con pPanel->pContainer,
    * sin distinguir si ese contenedor tiene mas de un panel
    * tabificado -- sacaba el contenedor ENTERO del arbol, llevandose
    * de arrastre a cualquier otro panel tabificado junto con este.
    * Se delega en hbDockManagerUndockPanel, que ya maneja ese caso
    * correctamente (saca solo este panel de la pestaña si hay mas
    * de uno en el grupo).
    */
   hbDockManagerUndockPanel(
      pMgr,
      pPanel );

   return TRUE;
}

BOOL hbDockAutoHideRestorePanel(
        void * pManager,
        LPCTSTR pszPanel )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pPanel;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pPanel = hbDockManagerFindPanel(
      pMgr,
      pszPanel );

   if( pPanel == NULL )
      return FALSE;

   hbDockManagerAutoHideRestore(
      pMgr,
      pPanel );

   return TRUE;
}

BOOL hbDockTabifyPanel(
        void * pManager,
        LPCTSTR pszSource,
        LPCTSTR pszTarget )
{
   HB_DOCK_MANAGER * pMgr;
   HB_DOCK_PANEL * pSource;
   HB_DOCK_PANEL * pTarget;

   pMgr = ( HB_DOCK_MANAGER * ) pManager;

   if( pMgr == NULL )
      return FALSE;

   pSource = hbDockManagerFindPanel(
      pMgr,
      pszSource );

   pTarget = hbDockManagerFindPanel(
      pMgr,
      pszTarget );

   if( pSource == NULL || pTarget == NULL )
      return FALSE;

   if( pTarget->pContainer == NULL )
      return FALSE;

   return hbDockManagerTabifyPanel(
      pMgr,
      pTarget->pContainer,
      pSource );
}

BOOL hbDockSaveWorkspace(
        void * pManager,
        LPCTSTR pszFile )
{
   if( pManager == NULL )
      return FALSE;

   return hbDockWorkspaceSave(
      ( HB_DOCK_MANAGER * ) pManager,
      pszFile );
}

BOOL hbDockLoadWorkspace(
        void * pManager,
        LPCTSTR pszFile )
{
   if( pManager == NULL )
      return FALSE;

   return hbDockWorkspaceLoad(
      ( HB_DOCK_MANAGER * ) pManager,
      pszFile );
}

/*
 * Nota de estabilizacion: la ventana principal en FiveWin puede no
 * tener todavia su tamano final en el momento en que se acoplan los
 * primeros paneles (DEFINE WINDOW / ON INIT), y HBDock32 no tenia
 * ningun gancho de WM_SIZE que corrigiera el layout mas adelante
 * cuando la ventana si tiene su tamano real. Se expone esta funcion
 * para que la app la llame desde ON RESIZE (o cuando haga falta),
 * forzando un recalculo contra el tamano actual de verdad.
 */
BOOL hbDockRefreshLayout(
        void * pManager )
{
   if( pManager == NULL )
      return FALSE;

   return hbDockManagerLayout(
      ( HB_DOCK_MANAGER * ) pManager );
}

/*
 * Etapa 28: ver nota en hbdockhost.c (hbDockHostPaintCaptions) --
 * version acotada, solo toca las ventanas de caption puntuales.
 */
void hbDockRepaintCaptions(
        void * pManager )
{
   HB_DOCK_MANAGER * p;

   if( pManager == NULL )
      return;

   p = ( HB_DOCK_MANAGER * ) pManager;

   if( p->pHost == NULL )
      return;

   hbDockHostPaintCaptions(
      p->pHost );
}

/*
 * Etapa 29: diagnostico -- recorre el arbol y arma un texto con el
 * estado REAL (no supuesto) de cada ventana de caption: si el
 * puntero de contenedor existe, si su hWnd es una ventana Win32
 * valida, si esta visible, y su rect actual. Buffer estatico (uso
 * de diagnostico puntual, no pensado para produccion).
 */
static char s_szDebugBuffer[ 4096 ];

static void hbDockDebugCaptionsNode(
   HB_DOCK_LAYOUT_NODE * pNode,
   char * pBuffer,
   int nBufferSize )
{
   char szLine[ 256 ];
   int nLen;

   if( pNode == NULL )
      return;

   if( pNode->Type == HB_LAYOUT_LEAF )
   {
      HB_DOCK_CONTAINER * pContainer;
      HB_DOCK_PANEL * pPanel;

      pContainer = pNode->pContainer;

      if( pContainer == NULL )
      {
         wsprintf(
            szLine,
            "leaf sin contenedor\r\n" );
      }
      else
      {
         pPanel = pContainer->TabGroup.pPanel;

         wsprintf(
            szLine,
            "cont=%p hWnd=%p IsWindow=%d IsVisible=%d rect={%d,%d,%d,%d} panel=%s\r\n",
            ( void * ) pContainer,
            ( void * ) pContainer->hWnd,
            pContainer->hWnd != NULL ?
               IsWindow( pContainer->hWnd ) : -1,
            pContainer->hWnd != NULL ?
               IsWindowVisible( pContainer->hWnd ) : -1,
            pContainer->Rect.left,
            pContainer->Rect.top,
            pContainer->Rect.right,
            pContainer->Rect.bottom,
            ( pPanel != NULL && pPanel->Caption[ 0 ] != '\0' ) ?
               pPanel->Caption : "(sin panel)" );
      }

      nLen = lstrlen( pBuffer );

      if( nLen + ( int ) lstrlen( szLine ) < nBufferSize - 1 )
         lstrcat(
            pBuffer,
            szLine );

      return;
   }

   hbDockDebugCaptionsNode(
      pNode->First,
      pBuffer,
      nBufferSize );

   hbDockDebugCaptionsNode(
      pNode->Second,
      pBuffer,
      nBufferSize );
}

const char * hbDockDebugCaptions(
        void * pManager )
{
   HB_DOCK_MANAGER * p;

   s_szDebugBuffer[ 0 ] = '\0';

   if( pManager == NULL )
      return s_szDebugBuffer;

   p = ( HB_DOCK_MANAGER * ) pManager;

   hbDockDebugCaptionsNode(
      p->LayoutTree.Root,
      s_szDebugBuffer,
      sizeof( s_szDebugBuffer ) );

   return s_szDebugBuffer;
}

/*
 * Etapa 37: ver nota en hbdockmanager.h -- reserva nMargin pixeles
 * arriba, restados SIEMPRE de GetClientRect antes de calcular el
 * area disponible para acoplar paneles (hbDockManagerLayout,
 * hbDockManagerRefreshLayout). Llamar UNA vez, justo despues de
 * crear la toolbar, con su altura real (ej. oBar:nHeight).
 */
void hbDockSetTopMargin(
        void * pManager,
        int nMargin )
{
   HB_DOCK_MANAGER * p;

   if( pManager == NULL )
      return;

   p = ( HB_DOCK_MANAGER * ) pManager;

   if( nMargin < 0 )
      nMargin = 0;

   p->TopMargin = nMargin;
}
