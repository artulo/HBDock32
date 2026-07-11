#ifndef HBDOCKAUTOHIDECURSOR_H
#define HBDOCKAUTOHIDECURSOR_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

HCURSOR hbDockAutoHideLoadCursor(
   LPCTSTR lpName );

void hbDockAutoHideSetCursor(
   HCURSOR hCursor );

#ifdef __cplusplus
}
#endif

#endif