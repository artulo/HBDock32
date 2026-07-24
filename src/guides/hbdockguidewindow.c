#include <windows.h>

#include "hbdockguidewindow.h"

static BOOL s_Registered = FALSE;

static LRESULT CALLBACK
hbDockGuideWindowProc(
   HWND hWnd,
   UINT message,
   WPARAM wParam,
   LPARAM lParam )
{
   switch( message )
   {
      case WM_ERASEBKGND:

         return 1;

      case WM_PAINT:
      {
         PAINTSTRUCT ps;
         HDC hDC;
         RECT rc;
         HBRUSH hBrush;

         hDC =
            BeginPaint(
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
      message,
      wParam,
      lParam );
}

BOOL hbDockGuideWindowRegister(
   HINSTANCE hInstance )
{
   WNDCLASS wc;

   if( s_Registered )
      return TRUE;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.lpfnWndProc =
      hbDockGuideWindowProc;

   wc.hInstance =
      hInstance;

   wc.lpszClassName =
      TEXT( "HBDockGuideWindow" );

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

   s_Registered = TRUE;

   return TRUE;
}

HWND hbDockGuideWindowCreate(
   HWND hParent )
{
   HINSTANCE hInst;

   hInst =
      (HINSTANCE)
      GetWindowLongPtr(
         hParent,
         GWLP_HINSTANCE );

   if( !hbDockGuideWindowRegister(
            hInst ) )
      return NULL;

   return CreateWindowEx(
      WS_EX_LAYERED |
      WS_EX_TOOLWINDOW |
      WS_EX_TOPMOST,

      TEXT( "HBDockGuideWindow" ),

      TEXT( "" ),

      WS_POPUP,

      0,
      0,
      0,
      0,

      hParent,

      NULL,

      hInst,

      NULL );
}

void hbDockGuideWindowDestroy(
   HWND hWnd )
{
   if( hWnd != NULL )
      DestroyWindow(
         hWnd );
}

void hbDockGuideWindowShow(
   HWND hWnd )
{
   if( hWnd != NULL )
      ShowWindow(
         hWnd,
         SW_SHOWNA );
}

void hbDockGuideWindowHide(
   HWND hWnd )
{
   if( hWnd != NULL )
      ShowWindow(
         hWnd,
         SW_HIDE );
}

void hbDockGuideWindowMove(
   HWND hWnd,
   const RECT * pRect )
{
   if( hWnd == NULL )
      return;

   if( pRect == NULL )
      return;

   MoveWindow(
      hWnd,
      pRect->left,
      pRect->top,
      pRect->right - pRect->left,
      pRect->bottom - pRect->top,
      TRUE );
}