#include <windows.h>

#include "hbdockautohidetimerproc.h"

VOID CALLBACK hbDockAutoHideTimerProc(
   HWND hwnd,
   UINT uMsg,
   UINT_PTR idEvent,
   DWORD dwTime )
{
   HB_SYMBOL_UNUSED( hwnd );
   HB_SYMBOL_UNUSED( uMsg );
   HB_SYMBOL_UNUSED( idEvent );
   HB_SYMBOL_UNUSED( dwTime );
}