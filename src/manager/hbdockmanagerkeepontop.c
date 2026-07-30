#include <windows.h>

#include "hbdockmanagerkeepontop.h"
#include "hbdockpanel.h"
#include "hbdockfloating.h"
#include "hbdockhost.h"
#include "hbdockmanagerlayout.h"

#define HBDOCK_PROP_MANAGER   TEXT( "HBDock32_Manager" )
#define HBDOCK_PROP_OLDPROC   TEXT( "HBDock32_OldWndProc" )

/*
 * Nota de estabilizacion (Etapa 13): pedido explicito -- un panel
 * flotante (WS_POPUP con la ventana principal como "owner", ver
 * hbdockfloating.c) no debe quedar tapado detras de la ventana
 * principal al hacer click sobre ella.
 *
 * Originalmente esto se resolvia forzando SetWindowPos(HWND_TOP) en
 * cada WM_ACTIVATE de la ventana principal. Reemplazado en la Etapa
 * 45 por hover-activation (ver abajo): ese mecanismo viejo entraba
 * en conflicto directo con el nuevo -- cada vez que el hover
 * intentaba activar la ventana principal, el "siempre al frente"
 * volvia a subir el flotante encima, tapando visualmente el efecto.
 * Con hover-activation, el orden correcto lo da la propia activacion
 * de Windows (la ventana que se activa sube sola al frente).
 *
 * Se subclasea la ventana principal (unico lugar de todo el
 * proyecto que lo hace). Se usan SetProp/GetProp (no GWLP_USERDATA)
 * para guardar el manager y el WndProc original en la ventana, para
 * no pisar nada que FiveWin pueda estar guardando ahi (su propio
 * puntero a objeto Self, tipicamente).
 *
 * Nota de estabilizacion (Etapa 15): ademas, este es el unico lugar
 * de todo el proyecto que subclasea la ventana principal -- asi que
 * es tambien el lugar correcto para rutear mouse/timer hacia
 * hbDockHostHandleMessage (src/host/hbdockhost.c), que ya
 * implementa TODA la logica de drag de paneles, splitters y hover
 * de autohide pero nunca estuvo conectada a mensajes reales. Se
 * rutean WM_LBUTTONDOWN/WM_MOUSEMOVE/WM_LBUTTONUP/WM_CAPTURECHANGED/
 * WM_TIMER; si el host devuelve TRUE (mensaje consumido por el
 * docking), se corta ahi -- no se reenvia al WndProc original, tal
 * como pide el contrato documentado de hbDockHostHandleMessage.
 * WM_LBUTTONDOWN sobre la ventana PRINCIPAL (no sobre un control
 * hijo de FiveWin, que recibe sus propios mensajes directo) es
 * exactamente donde viven los captions/splitters pintados por el
 * arbol de layout, asi que esto no interfiere con los controles
 * normales de la ventana.
 *
 * Nota de estabilizacion (Etapa 30): tambien se maneja aca un timer
 * de un solo disparo (HBDOCK_FIRSTPAINT_TIMER_ID) que fuerza, 300ms
 * despues de crear el manager, un recalculo real de geometria
 * (hbDockManagerLayout) y un repintado de captions -- los Dock() de
 * ON INIT corren con la ventana principal todavia oculta, y sin
 * esto algunos paneles/captions no se veian bien hasta la primera
 * interaccion real del usuario.
 */

static LRESULT CALLBACK hbDockMainWndProc(
   HWND hWnd,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   HB_DOCK_MANAGER * pManager;
   WNDPROC OldProc;

   pManager =
      ( HB_DOCK_MANAGER * )
      GetProp(
         hWnd,
         HBDOCK_PROP_MANAGER );

   OldProc =
      ( WNDPROC )
      GetProp(
         hWnd,
         HBDOCK_PROP_OLDPROC );

   /*
    * Etapa 30: timer de un solo disparo para el primer repintado de
    * captions -- se maneja aca directamente (no via
    * hbDockHostHandleMessage, que es para los timers recurrentes de
    * autohide/animacion) porque solo necesita dispararse una vez y
    * matarse. Independiente de TTimer/DEFINE TIMER de FiveWin (que
    * resulto no dispararse de forma confiable en este proyecto).
    *
    * Etapa 31: hbDockManagerLayout (GetClientRect + Recalc, SIN
    * RDW_ALLCHILDREN) corrige la geometria de paneles/captions.
    *
    * Etapa 36: ademas, un RedrawWindow con RDW_ALLCHILDREN sobre
    * toda la ventana principal, a los 300ms (momento ya confirmado
    * seguro -- a diferencia de hacer esto en WM_ACTIVATE, que
    * interrumpe la construccion interna de FiveWin y rompe la
    * toolbar), asegura que todo quede bien pintado desde el
    * arranque sin depender de que el usuario interactue primero.
    */
   if( pManager != NULL &&
       uMsg == WM_TIMER &&
       wParam == HBDOCK_FIRSTPAINT_TIMER_ID )
   {
      KillTimer(
         hWnd,
         HBDOCK_FIRSTPAINT_TIMER_ID );

      if( pManager->hMainWnd != NULL )
         hbDockManagerLayout(
            pManager );

      if( pManager->pHost != NULL )
         hbDockHostPaintCaptions(
            pManager->pHost );

      if( pManager->hMainWnd != NULL )
      {
         RedrawWindow(
            pManager->hMainWnd,
            NULL,
            NULL,
            RDW_INVALIDATE |
            RDW_ALLCHILDREN |
            RDW_UPDATENOW |
            RDW_ERASE );
      }

      return 0;
   }

   /*
    * Etapa 44: activacion por hover -- pedido explicito de que la
    * ventana activa cambie dinamicamente segun donde este el mouse
    * (sobre la principal = principal activa; sobre un flotante =
    * ese flotante activo), sin necesitar click.
    *
    * WM_MOUSEMOVE de la ventana principal NO alcanza para esto: solo
    * dispara cuando el mouse esta sobre SU area directa, no sobre
    * los controles hijos (los paneles reparentados adentro de cada
    * flotante tienen su propia ventana, con sus propios mensajes de
    * mouse). Se aprovecha en cambio el timer de autohide, que ya
    * dispara cada ~200ms: en cada tick, se mira DONDE ESTA el cursor
    * de verdad (WindowFromPoint) y se sube hasta su ventana de nivel
    * superior (GetAncestor GA_ROOT) -- cubre toda el area de cada
    * ventana, hijos incluidos, sin subclasear nada mas. Si esa
    * ventana de nivel superior es la principal o algun flotante
    * NUESTRO, y no es ya la activa, se activa.
    */
   if( pManager != NULL &&
       pManager->FloatingCount > 0 &&
       uMsg == WM_TIMER &&
       wParam == HBDOCK_AUTOHIDE_TIMER_ID )
   {
      POINT pt;
      HWND hUnderCursor;

      GetCursorPos(
         &pt );

      hUnderCursor =
         WindowFromPoint(
            pt );

      if( hUnderCursor != NULL )
      {
         HWND hTopLevel;

         hTopLevel =
            GetAncestor(
               hUnderCursor,
               GA_ROOT );

         if( hTopLevel != NULL &&
             hTopLevel != GetActiveWindow() )
         {
            if( hTopLevel == hWnd )
            {
               SetActiveWindow(
                  hTopLevel );
            }
            else
            {
               HB_DOCK_PANEL * pPanel;

               for( pPanel = pManager->Registry.First;
                    pPanel != NULL;
                    pPanel = pPanel->Next )
               {
                  if( pPanel->Floating &&
                      pPanel->pFloating != NULL &&
                      pPanel->pFloating->hWnd == hTopLevel )
                  {
                     SetActiveWindow(
                        hTopLevel );
                     break;
                  }
               }
            }
         }
      }
   }

   /*
    * Etapa 48: pintado 3D de los splitters -- se deja que el WndProc
    * original pinte primero (FiveWin/paneles, normal), y RECIEN
    * DESPUES se pintan los splitters encima con un DC fresco (no
    * hace falta BeginPaint/EndPaint aca, la region ya quedo validada
    * por el pintado normal de arriba).
    */
   if( pManager != NULL &&
       pManager->pHost != NULL &&
       uMsg == WM_PAINT )
   {
      LRESULT lResult;
      HDC hDC;

      if( OldProc != NULL )
         lResult =
            CallWindowProc(
               OldProc,
               hWnd,
               uMsg,
               wParam,
               lParam );
      else
         lResult =
            DefWindowProc(
               hWnd,
               uMsg,
               wParam,
               lParam );

      hDC =
         GetDC(
            hWnd );

      if( hDC != NULL )
      {
         hbDockHostPaintSplitters(
            pManager->pHost,
            hDC );

         /* Etapa 53 */
         hbDockHostPaintAutoHideTabs(
            pManager->pHost,
            hDC );

         ReleaseDC(
            hWnd,
            hDC );
      }

      return lResult;
   }

   /*
    * Etapa 15: mouse/timer real de docking -- ver nota de arriba.
    * Se chequea ANTES que WM_ACTIVATE porque son mensajes disjuntos
    * (nunca se superponen), el orden entre ambos bloques no importa.
    */
   if( pManager != NULL &&
       pManager->pHost != NULL &&
       ( uMsg == WM_LBUTTONDOWN ||
         uMsg == WM_MOUSEMOVE ||
         uMsg == WM_LBUTTONUP ||
         uMsg == WM_CAPTURECHANGED ||
         uMsg == WM_TIMER ) )
   {
      if( hbDockHostHandleMessage(
             pManager->pHost,
             uMsg,
             wParam,
             lParam ) )
         return 0;
   }

   if( OldProc != NULL )
      return CallWindowProc(
         OldProc,
         hWnd,
         uMsg,
         wParam,
         lParam );

   return DefWindowProc(
      hWnd,
      uMsg,
      wParam,
      lParam );
}

BOOL hbDockManagerKeepFloatingOnTopInstall(
   HB_DOCK_MANAGER * pManager )
{
   WNDPROC OldProc;

   if( pManager == NULL || pManager->hMainWnd == NULL )
      return FALSE;

   SetProp(
      pManager->hMainWnd,
      HBDOCK_PROP_MANAGER,
      ( HANDLE ) pManager );

   OldProc =
      ( WNDPROC )
      SetWindowLongPtr(
         pManager->hMainWnd,
         GWLP_WNDPROC,
         ( LONG_PTR ) hbDockMainWndProc );

   SetProp(
      pManager->hMainWnd,
      HBDOCK_PROP_OLDPROC,
      ( HANDLE ) OldProc );

   return TRUE;
}

void hbDockManagerKeepFloatingOnTopRemove(
   HB_DOCK_MANAGER * pManager )
{
   WNDPROC OldProc;

   if( pManager == NULL || pManager->hMainWnd == NULL )
      return;

   OldProc =
      ( WNDPROC )
      GetProp(
         pManager->hMainWnd,
         HBDOCK_PROP_OLDPROC );

   if( OldProc != NULL )
      SetWindowLongPtr(
         pManager->hMainWnd,
         GWLP_WNDPROC,
         ( LONG_PTR ) OldProc );

   RemoveProp(
      pManager->hMainWnd,
      HBDOCK_PROP_MANAGER );

   RemoveProp(
      pManager->hMainWnd,
      HBDOCK_PROP_OLDPROC );
}
