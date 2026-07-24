#include <windows.h>

#include "hbdockpreviewoverlay.h"
#include "hbdockpreviewpaint.h"

#define HBDOCK_PREVIEW_CLASS TEXT("HBDockPreviewOverlay")

static LRESULT CALLBACK hbDockPreviewWndProc(
   HWND hWnd,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( uMsg )
   {
      case WM_PAINT:
      {
         PAINTSTRUCT ps;
         RECT rcClient;

         BeginPaint(
            hWnd,
            &ps );

         GetClientRect(
            hWnd,
            &rcClient );

         hbDockPreviewPaint(
            ps.hdc,
            &rcClient );

         EndPaint(
            hWnd,
            &ps );

         return 0;
      }
   }

   return DefWindowProc(
      hWnd,
      uMsg,
      wParam,
      lParam );
}
BOOL hbDockPreviewOverlayRegisterClass(
   HINSTANCE hInstance )
{
   WNDCLASS wc;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockPreviewWndProc;
   wc.hInstance = hInstance;
   wc.lpszClassName = HBDOCK_PREVIEW_CLASS;
   wc.hCursor = LoadCursor(
      NULL,
      IDC_ARROW );

   if( GetClassInfo(
          hInstance,
          HBDOCK_PREVIEW_CLASS,
          &wc ) )
      return TRUE;

   return RegisterClass(
      &wc ) != 0;
}

BOOL hbDockPreviewOverlayCreate(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   HWND hOwner )
{
   HINSTANCE hInst;

   if( pOverlay == NULL )
      return FALSE;

   ZeroMemory(
      pOverlay,
      sizeof( HB_DOCK_PREVIEW_OVERLAY ) );

   hInst =
      ( HINSTANCE ) GetWindowLongPtr(
         hOwner,
         GWLP_HINSTANCE );

   if( !hbDockPreviewOverlayRegisterClass(
            hInst ) )
      return FALSE;

   pOverlay->hOwner = hOwner;
   pOverlay->Alpha = 96;

   SetRectEmpty(
      &pOverlay->PreviewRect );

   pOverlay->hWnd =
      CreateWindowEx(
         WS_EX_TOOLWINDOW |
         WS_EX_LAYERED,
         HBDOCK_PREVIEW_CLASS,
         TEXT(""),
         WS_POPUP,
         0,
         0,
         0,
         0,
         hOwner,
         NULL,
         hInst,
         NULL );

   if( pOverlay->hWnd == NULL )
      return FALSE;

   SetLayeredWindowAttributes(
      pOverlay->hWnd,
      0,
      pOverlay->Alpha,
      LWA_ALPHA );

   return TRUE;
}

void hbDockPreviewOverlayDestroy(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay )
{
   if( pOverlay == NULL )
      return;

   if( pOverlay->hWnd != NULL )
   {
      DestroyWindow(
         pOverlay->hWnd );

      pOverlay->hWnd = NULL;
   }

   pOverlay->Visible = FALSE;
}

void hbDockPreviewOverlayShow(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   const RECT * pRect )
{
   if( pOverlay == NULL )
      return;

   if( pRect != NULL )
      hbDockPreviewOverlayMove(
         pOverlay,
         pRect );

   ShowWindow(
      pOverlay->hWnd,
      SW_SHOWNOACTIVATE );

   pOverlay->Visible = TRUE;
}

void hbDockPreviewOverlayHide(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay )
{
   if( pOverlay == NULL )
      return;

   ShowWindow(
      pOverlay->hWnd,
      SW_HIDE );

   pOverlay->Visible = FALSE;
}

void hbDockPreviewOverlayMove(
   HB_DOCK_PREVIEW_OVERLAY * pOverlay,
   const RECT * pRect )
{
   if( pOverlay == NULL )
      return;

   if( pRect == NULL )
      return;

   pOverlay->PreviewRect = *pRect;

   MoveWindow(
      pOverlay->hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      TRUE );
}

BOOL hbDockPreviewOverlayVisible(
   const HB_DOCK_PREVIEW_OVERLAY * pOverlay )
{
   if( pOverlay == NULL )
      return FALSE;

   return pOverlay->Visible;
}