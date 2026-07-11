#ifndef HBDOCKAUTOHIDEBUTTONCURSOR_H
#define HBDOCKAUTOHIDEBUTTONCURSOR_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

HCURSOR hbDockAutoHideButtonLoadCursor(
   LPCTSTR lpName );

void hbDockAutoHideButtonSetCursor(
   HCURSOR hCursor );

#ifdef __cplusplus
}
#endif

#endif