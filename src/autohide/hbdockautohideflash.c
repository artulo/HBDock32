#include <windows.h>

#include "hbdockautohideflash.h"

BOOL hbDockAutoHideFlash(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   UINT uCount )
{
   FLASHWINFO fi;

   if( pPane == NULL )
      return FALSE;

   fi.cbSize = sizeof( fi );
   fi.hwnd = pPane->hWnd;
   fi.dwFlags = FLASHW_ALL;
   fi.uCount = uCount;
   fi.dwTimeout = 0;

   return FlashWindowEx(
      &fi );
}