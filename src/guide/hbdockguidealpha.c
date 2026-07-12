#include <windows.h>

#include "hbdockguidealpha.h"

BOOL hbDockGuideSetAlpha(
   HWND hWnd,
   BYTE Alpha )
{
   LONG exStyle;

   exStyle =
      GetWindowLong(
         hWnd,
         GWL_EXSTYLE );

   SetWindowLong(
      hWnd,
      GWL_EXSTYLE,
      exStyle | WS_EX_LAYERED );

   return SetLayeredWindowAttributes(
      hWnd,
      0,
      Alpha,
      LWA_ALPHA );
}