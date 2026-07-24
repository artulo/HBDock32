#include <windows.h>

#include "hbdockpreviewoverlay.h"

static LRESULT CALLBACK
hbDockPreviewOverlayProc(
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
         HBRUSH hBrush;

         hDC = BeginPaint(
            hWnd,
            &ps );

         GetClientRect(
            hWnd,
            &rc );

         hBrush =
            CreateSolidBrush(
               RGB( 0, 120, 215 ) );

         FillRect(
            hDC,
            &rc,
            hBrush );

         DeleteObject(
            hBrush );

         EndPaint(
            hWnd,
            &ps );

         return 0;
      }
   }

   return DefWindowProc(
      hWnd,
      msg,
      wParam,
      lParam );
}

static BOOL s_ClassRegistered = FALSE;

BOOL hbDockPreviewOverlayRegisterClass(
   HINSTANCE hInstance )
{
   WNDCLASS wc;

   if( s_ClassRegistered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc = hbDockPreviewOverlayProc;

   wc.hInstance = hInstance;

   wc.lpszClassName =
      TEXT( "HBDockPreviewOverlay" );

   wc.hCursor =
      LoadCursor(
         NULL,
         IDC_ARROW );

   wc.hbrBackground =
      (HBRUSH)GetStockObject(
         NULL_BRUSH );

   if( !RegisterClass(
            &wc ) )
      return FALSE;

   s_ClassRegistered = TRUE;

   return TRUE;
}