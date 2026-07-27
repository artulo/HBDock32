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
