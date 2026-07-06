#include <windows.h>

#include "hbdockfloating.h"

#define HBDOCK_FLOAT_CLASS "HBDockFloating"

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
   HB_DOCK_PANEL * pPanel )
{
   if( pFloating == NULL )
      return FALSE;

   if( !hbDockFloatingRegister(
         hInstance ) )
      return FALSE;

   pFloating->hWnd =
      CreateWindowEx(
         WS_EX_TOOLWINDOW,
         HBDOCK_FLOAT_CLASS,
         "",
         WS_POPUP |
         WS_CAPTION |
         WS_THICKFRAME |
         WS_SYSMENU,
         CW_USEDEFAULT,
         CW_USEDEFAULT,
         300,
         300,
         NULL,
         NULL,
         hInstance,
         NULL );

   pFloating->Panel = pPanel;
   pFloating->Active = 0;

   return pFloating->hWnd != NULL;
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