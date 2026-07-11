#include <windows.h>

#include "hbdockautohideclass.h"

static LRESULT CALLBACK
hbDockAutoHideWndProc(
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

ATOM hbDockAutoHideRegisterClass(
   HINSTANCE hInstance )
{
   WNDCLASS wc;

   ZeroMemory(
      &wc,
      sizeof( wc ) );

   wc.style         = CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc   = hbDockAutoHideWndProc;
   wc.hInstance     = hInstance;
   wc.hCursor       = LoadCursor( NULL, IDC_ARROW );
   wc.hbrBackground = ( HBRUSH ) ( COLOR_BTNFACE + 1 );
   wc.lpszClassName = HB_DOCK_AUTOHIDE_CLASS;

   return RegisterClass(
      &wc );
}

void hbDockAutoHideUnregisterClass(
   HINSTANCE hInstance )
{
   UnregisterClass(
      HB_DOCK_AUTOHIDE_CLASS,
      hInstance );
}