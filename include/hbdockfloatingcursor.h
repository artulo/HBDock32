#ifndef HBDOCKFLOATINGCURSOR_H
#define HBDOCKFLOATINGCURSOR_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

HCURSOR hbDockFloatingLoadCursor(
   LPCTSTR pszCursor );

void hbDockFloatingSetCursor(
   HCURSOR hCursor );

#ifdef __cplusplus
}
#endif

#endif