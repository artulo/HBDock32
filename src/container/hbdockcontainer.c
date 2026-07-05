#include <windows.h>

#include "hbdockcontainer.h"
#include "hbdocklayout.h"

#define HB_DOCK_CONTAINER_CLASS "HBDockContainer"

static LRESULT CALLBACK hbDockContainerProc(
   HWND hWnd,
   UINT msg,
   WPARAM wParam,
   LPARAM lParam )
{
   HB_DOCK_MANAGER *pManager;

   pManager = ( HB_DOCK_MANAGER * )
      GetWindowLongPtr(
         hWnd,
         GWLP_USERDATA );

   switch( msg )
   {
      case WM_CREATE:
      {
         CREATESTRUCT *cs;

         cs = ( CREATESTRUCT * ) lParam;

         SetWindowLongPtr(
            hWnd,
            GWLP_USERDATA,
            ( LONG_PTR ) cs->lpCreateParams );

         return 0;
      }

      case WM_SIZE:

         if( pManager != NULL )
            hbDockPerformLayout( pManager );

         return 0;

      case WM_ERASEBKGND:
         return 1;

      case WM_PAINT:
      {
         PAINTSTRUCT ps;

         BeginPaint(
            hWnd,
            &ps );

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

BOOL hbDockContainerRegisterClass(
   HINSTANCE hInstance )
{
   WNDCLASS wc;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.style         = CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc   = hbDockContainerProc;
   wc.hInstance     = hInstance;
   wc.hCursor       = LoadCursor(
                         NULL,
                         IDC_ARROW );
   wc.hbrBackground = ( HBRUSH ) ( COLOR_BTNFACE + 1 );
   wc.lpszClassName = HB_DOCK_CONTAINER_CLASS;

   return RegisterClass( &wc ) != 0;
}

HWND hbDockContainerCreate(
   HWND hParent,
   HINSTANCE hInstance,
   HB_DOCK_MANAGER *pManager )
{
   return CreateWindowEx(
      0,
      HB_DOCK_CONTAINER_CLASS,
      "",
      WS_CHILD |
      WS_VISIBLE |
      WS_CLIPSIBLINGS |
      WS_CLIPCHILDREN,
      0,
      0,
      0,
      0,
      hParent,
      NULL,
      hInstance,
      pManager );
}