#include <windows.h>

#include "hbdockautohidetimerproc.h"
VOID CALLBACK hbDockAutoHideTimerProc(
   HWND hwnd,
   UINT uMsg,
   UINT_PTR idEvent,
   DWORD dwTime )
{
   (void)(hwnd);
   (void)(uMsg);
   (void)(idEvent);
   (void)(dwTime);
}