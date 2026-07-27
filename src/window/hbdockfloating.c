#include <windows.h>

#include "hbdockfloating.h"
#include "hbdockpanel.h"

#define HBDOCK_FLOAT_CLASS "HBDockFloating"

/*
 * Nota de estabilizacion (Etapa 9): esta ventana se creaba pero
 * quedaba vacia -- titulo en blanco (""), y el hWnd real del panel
 * (pPanel->hWnd) nunca se reparentaba adentro ni se movia con ella.
 * Flotar un panel mostraba una ventanita gris sin nada dentro. Se
 * corrige: WM_CREATE reparenta el panel como hijo y le pone el
 * titulo real; WM_SIZE lo estira para llenar el cliente; WM_DESTROY
 * lo devuelve a NULL como padre antes de que la ventana desaparezca
 * (si el panel se vuelve a acoplar despues, hbDockPanelSetParent lo
 * reparenta a donde corresponda).
 */

static LRESULT CALLBACK hbDockFloatingProc(
   HWND hWnd,
   UINT msg,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( msg )
   {
      case WM_ERASEBKGND:
         return 1;

      case WM_SIZE:
      {
         HB_DOCK_FLOATING * pFloating;
         RECT rc;

         pFloating = ( HB_DOCK_FLOATING * )
            GetWindowLongPtr( hWnd, GWLP_USERDATA );

         if( pFloating != NULL &&
             pFloating->Panel != NULL &&
             pFloating->Panel->hWnd != NULL )
         {
            GetClientRect(
               hWnd,
               &rc );

            MoveWindow(
               pFloating->Panel->hWnd,
               rc.left,
               rc.top,
               rc.right - rc.left,
               rc.bottom - rc.top,
               TRUE );
         }

         return 0;
      }

      case WM_CLOSE:
         ShowWindow(
            hWnd,
            SW_HIDE );
         return 0;
   }

   return DefWindowProc(
      hWnd,
      msg,
      wParam,
      lParam );
}

static BOOL hbDockFloatingRegister(
   HINSTANCE hInstance )
{
   static int Registered = 0;

   WNDCLASS wc;

   if( Registered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockFloatingProc;
   wc.hInstance = hInstance;
   wc.hCursor = LoadCursor(
      NULL,
      IDC_ARROW );
   wc.hbrBackground =
      ( HBRUSH ) ( COLOR_BTNFACE + 1 );
   wc.lpszClassName =
      HBDOCK_FLOAT_CLASS;

   Registered =
      RegisterClass( &wc );

   return Registered != 0;
}

BOOL hbDockFloatingCreate(
   HB_DOCK_FLOATING * pFloating,
   HINSTANCE hInstance,
   HB_DOCK_PANEL * pPanel,
   HWND hOwnerWnd )
{
   LPCTSTR pszCaption;

   if( pFloating == NULL )
      return FALSE;

   if( !hbDockFloatingRegister(
         hInstance ) )
      return FALSE;

   pszCaption =
      ( pPanel != NULL ) ? pPanel->Caption : "";

   /*
    * Nota de estabilizacion: el parametro de ventana "padre" de
    * CreateWindowEx, para una ventana WS_POPUP, es en realidad el
    * OWNER -- sin el, esta ventana flotante no tiene ninguna
    * relacion con la ventana principal, y puede terminar tapada
    * detras de ella con solo hacer click en la principal (Windows
    * no tiene motivo para mantenerla al frente si no sabe que le
    * "pertenece"). Confirmado con captura real: la ventana flotante
    * parecia "desaparecer" al clickear, pero seguia abierta, solo
    * que detras de la ventana principal.
    */
   pFloating->hWnd =
      CreateWindowEx(
         WS_EX_TOOLWINDOW,
         HBDOCK_FLOAT_CLASS,
         pszCaption,
         WS_POPUP |
         WS_CAPTION |
         WS_THICKFRAME |
         WS_SYSMENU,
         CW_USEDEFAULT,
         CW_USEDEFAULT,
         300,
         300,
         hOwnerWnd,
         NULL,
         hInstance,
         NULL );

   pFloating->Panel = pPanel;
   pFloating->Active = 0;

   if( pFloating->hWnd == NULL )
      return FALSE;

   SetWindowLongPtr(
      pFloating->hWnd,
      GWLP_USERDATA,
      ( LONG_PTR ) pFloating );

   if( pPanel != NULL && pPanel->hWnd != NULL )
   {
      SetParent(
         pPanel->hWnd,
         pFloating->hWnd );

      ShowWindow(
         pPanel->hWnd,
         SW_SHOW );
   }

   return TRUE;
}

void hbDockFloatingDestroy(
   HB_DOCK_FLOATING * pFloating )
{
   if( pFloating == NULL )
      return;

   if( pFloating->hWnd != NULL )
      DestroyWindow(
         pFloating->hWnd );

   pFloating->hWnd = NULL;
}

void hbDockFloatingShow(
   HB_DOCK_FLOATING * pFloating,
   int Show )
{
   if( pFloating == NULL )
      return;

   if( pFloating->hWnd == NULL )
      return;

   ShowWindow(
      pFloating->hWnd,
      Show ? SW_SHOW : SW_HIDE );

   pFloating->Active = Show;
}

void hbDockFloatingMove(
   HB_DOCK_FLOATING * pFloating,
   const RECT * pRect )
{
   if( pFloating == NULL )
      return;

   if( pFloating->hWnd == NULL )
      return;

   MoveWindow(
      pFloating->hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      TRUE );

   pFloating->RestoreRect = *pRect;
}