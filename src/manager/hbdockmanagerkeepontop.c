#include <windows.h>

#include "hbdockmanagerkeepontop.h"
#include "hbdockpanel.h"
#include "hbdockfloating.h"

#define HBDOCK_PROP_MANAGER   TEXT( "HBDock32_Manager" )
#define HBDOCK_PROP_OLDPROC   TEXT( "HBDock32_OldWndProc" )

/*
 * Nota de estabilizacion (Etapa 13): pedido explicito -- un panel
 * flotante (WS_POPUP con la ventana principal como "owner", ver
 * hbdockfloating.c) no debe quedar tapado detras de la ventana
 * principal al hacer click sobre ella.
 *
 * En teoria Windows mantiene un WS_POPUP owned siempre por encima de
 * su owner en el z-order, pero en la practica esa garantia no se
 * sostiene de forma confiable con solo clickear la ventana
 * principal -- es un problema conocido y comun en apps con paneles
 * flotantes tipo herramienta. Ademas, revisando todo el proyecto
 * (src/host/hbdockhost.c, hbDockHostHandleMessage/hbDockHostAttach)
 * se confirma que HBDock32 no tiene ningun gancho real a los
 * mensajes de la ventana principal todavia -- existen las funciones
 * pero no estan enganchadas a ningun WndProc real (el drag de mouse
 * en general queda pendiente como tarea aparte). Sin ese gancho, no
 * hay forma de reforzar el z-order cuando hace falta.
 *
 * Se subclasea la ventana principal (unico lugar de todo el
 * proyecto que lo hace) y, cada vez que se activa por click
 * (WM_ACTIVATE con wParam != WA_INACTIVE), se hace SetWindowPos con
 * HWND_TOP + SWP_NOACTIVATE sobre cada panel flotante visible --
 * corrige el orden de dibujado sin robarle el foco a la ventana
 * principal. Se usan SetProp/GetProp (no GWLP_USERDATA) para guardar
 * el manager y el WndProc original en la ventana, para no pisar
 * nada que FiveWin pueda estar guardando ahi (su propio puntero a
 * objeto Self, tipicamente).
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

   if( pManager != NULL &&
       uMsg == WM_ACTIVATE &&
       LOWORD( wParam ) != WA_INACTIVE )
   {
      HB_DOCK_PANEL * pPanel;

      for( pPanel = pManager->Registry.First;
           pPanel != NULL;
           pPanel = pPanel->Next )
      {
         if( pPanel->Floating &&
             pPanel->pFloating != NULL &&
             pPanel->pFloating->hWnd != NULL &&
             IsWindowVisible( pPanel->pFloating->hWnd ) )
         {
            SetWindowPos(
               pPanel->pFloating->hWnd,
               HWND_TOP,
               0, 0, 0, 0,
               SWP_NOMOVE |
               SWP_NOSIZE |
               SWP_NOACTIVATE );
         }
      }
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
