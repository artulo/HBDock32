#include <windows.h>

#include "hbdockautohideflash.h"

BOOL hbDockAutoHideFlash(
   HB_DOCK_AUTOHIDE * pAutoHide,
   UINT uCount )
{
   FLASHWINFO fi;

   if( pAutoHide == NULL )
      return FALSE;

   if( pAutoHide->Panel == NULL )
      return FALSE;

   if( pAutoHide->Panel->hWnd == NULL )
      return FALSE;

   fi.cbSize = sizeof( FLASHWINFO );
   fi.hwnd = pAutoHide->Panel->hWnd;
   fi.dwFlags = FLASHW_ALL;
   fi.uCount = uCount;
   fi.dwTimeout = 0;

   return FlashWindowEx( &fi );
}