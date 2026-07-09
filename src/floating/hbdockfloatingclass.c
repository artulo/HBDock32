#include <windows.h>

#include "hbdockfloatingclass.h"

static LRESULT CALLBACK
hbDockFloatingWndProc(
   HWND hWnd,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam )
{
   return DefWindowProc(
      hWnd,
      uMsg,
      wParam,
      lParam );
}

ATOM hbDockFloatingRegisterClass(
   HINSTANCE hInstance )
{
   WNDCLASS wc;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.style =
      CS_HREDRAW |
      CS_VREDRAW;

   wc.lpfnWndProc =
      hbDockFloatingWndProc;

   wc.hInstance =
      hInstance;

   wc.hCursor =
      LoadCursor(
         NULL,
         IDC_ARROW );

   wc.hbrBackground =
      ( HBRUSH )
      ( COLOR_BTNFACE + 1 );

   wc.lpszClassName =
      HB_DOCK_FLOATING_CLASS;

   return RegisterClass(
      &wc );
}

void hbDockFloatingUnregisterClass(
   HINSTANCE hInstance )
{
   UnregisterClass(
      HB_DOCK_FLOATING_CLASS,
      hInstance );
}