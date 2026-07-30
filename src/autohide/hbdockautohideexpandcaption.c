#include <windows.h>
#include <windowsx.h>

#include "hbdockautohideexpandcaption.h"
#include "hbdockcaption.h"
#include "hbdockmanagerautohide.h"

#define HBDOCK_AUTOHIDE_EXPCAP_CLASS   TEXT( "HBDockAutoHideExpandCaption" )

/*
 * Etapa 58: datos del panel actualmente mostrado en esta ventana --
 * singleton (solo un panel puede estar expandido a la vez), no hace
 * falta GWLP_USERDATA por-ventana para esto.
 */
static HB_DOCK_MANAGER * s_pManager = NULL;
static HB_DOCK_PANEL * s_pPanel = NULL;

static LRESULT CALLBACK hbDockAutoHideExpandCaptionProc(
   HWND hWnd,
   UINT msg,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( msg )
   {
      case WM_ERASEBKGND:
         return 1;

      case WM_PAINT:
      {
         PAINTSTRUCT ps;
         HDC hDC;
         RECT rc;

         hDC =
            BeginPaint(
               hWnd,
               &ps );

         GetClientRect(
            hWnd,
            &rc );

         if( s_pPanel != NULL )
         {
            HB_DOCK_CAPTION Caption;

            hbDockCaptionInit(
               &Caption,
               s_pPanel );

            hbDockCaptionLayout(
               &Caption,
               &rc );

            hbDockCaptionDraw(
               hDC,
               &Caption );
         }

         EndPaint(
            hWnd,
            &ps );

         return 0;
      }

      case WM_LBUTTONDOWN:
      {
         RECT rc;
         POINT pt;

         pt.x = GET_X_LPARAM( lParam );
         pt.y = GET_Y_LPARAM( lParam );

         GetClientRect(
            hWnd,
            &rc );

         if( s_pPanel != NULL && s_pManager != NULL )
         {
            HB_DOCK_CAPTION Caption;
            HB_DOCK_PANEL * pPanel;
            HB_DOCK_MANAGER * pManager;

            hbDockCaptionInit(
               &Caption,
               s_pPanel );

            hbDockCaptionLayout(
               &Caption,
               &rc );

            pPanel = s_pPanel;
            pManager = s_pManager;

            if( PtInRect( &Caption.PinRect, pt ) )
            {
               /*
                * Pin -- reactivar de forma PERMANENTE (redockear).
                * Ocultar esta ventana ANTES de llamar a Restore --
                * Restore reacopla el panel en el arbol normal, y
                * esta ventana (que solo tiene sentido para el modo
                * "temporalmente expandido") no debe seguir mostrada
                * encima de un panel que ya volvio a ser un panel
                * acoplado normal (con su propio caption real, del
                * sistema de captions de siempre).
                */
               hbDockAutoHideExpandCaptionHide(
                  pManager );

               hbDockManagerAutoHideRestore(
                  pManager,
                  pPanel );

               return 0;
            }

            if( PtInRect( &Caption.CloseRect, pt ) )
            {
               /*
                * "x" -- solo replegar de nuevo (sigue en autohide,
                * no se pierde el estado, simplemente deja de estar
                * expandido).
                */
               hbDockAutoHideExpandCaptionHide(
                  pManager );

               hbDockManagerAutoHideCollapse(
                  pManager,
                  pPanel );

               return 0;
            }
         }

         return 0;
      }
   }

   return DefWindowProc(
      hWnd,
      msg,
      wParam,
      lParam );
}

static BOOL hbDockAutoHideExpandCaptionRegister(
   HINSTANCE hInstance )
{
   static int Registered = 0;

   WNDCLASS wc;

   if( Registered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockAutoHideExpandCaptionProc;
   wc.hInstance = hInstance;
   wc.hCursor =
      LoadCursor(
         NULL,
         IDC_ARROW );
   wc.lpszClassName = HBDOCK_AUTOHIDE_EXPCAP_CLASS;

   Registered =
      RegisterClass( &wc );

   return Registered != 0;
}

void hbDockAutoHideExpandCaptionShow(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   const RECT * pRect )
{
   if( pManager == NULL || pPanel == NULL || pRect == NULL )
      return;

   if( pManager->AutoHideManager.hExpandCaptionWnd == NULL )
   {
      hbDockAutoHideExpandCaptionRegister(
         GetModuleHandle( NULL ) );

      pManager->AutoHideManager.hExpandCaptionWnd =
         CreateWindowEx(
            0,
            HBDOCK_AUTOHIDE_EXPCAP_CLASS,
            TEXT( "" ),
            WS_CHILD,
            0, 0, 0, 0,
            pManager->hMainWnd,
            NULL,
            GetModuleHandle( NULL ),
            NULL );
   }

   if( pManager->AutoHideManager.hExpandCaptionWnd == NULL )
      return;

   s_pManager = pManager;
   s_pPanel = pPanel;

   SetWindowPos(
      pManager->AutoHideManager.hExpandCaptionWnd,
      HWND_TOP,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      SWP_SHOWWINDOW );

   InvalidateRect(
      pManager->AutoHideManager.hExpandCaptionWnd,
      NULL,
      TRUE );
}

void hbDockAutoHideExpandCaptionHide(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   if( pManager->AutoHideManager.hExpandCaptionWnd != NULL )
      ShowWindow(
         pManager->AutoHideManager.hExpandCaptionWnd,
         SW_HIDE );

   s_pManager = NULL;
   s_pPanel = NULL;
}
