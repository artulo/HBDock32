#ifndef HBDOCKAUTOHIDETIMERPROC_H
#define HBDOCKAUTOHIDETIMERPROC_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

VOID CALLBACK hbDockAutoHideTimerProc(
   HWND hwnd,
   UINT uMsg,
   UINT_PTR idEvent,
   DWORD dwTime );

#ifdef __cplusplus
}
#endif

#endif