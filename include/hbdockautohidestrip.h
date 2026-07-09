#ifndef HBDOCKAUTOHIDESTRIP_H
#define HBDOCKAUTOHIDESTRIP_H

#include <windows.h>

#include "hbdockarray.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HWND hWnd;
   DWORD Side;
   HB_DOCK_ARRAY Buttons;

} HB_DOCK_AUTOHIDE_STRIP;

void hbDockAutoHideStripInit(
   HB_DOCK_AUTOHIDE_STRIP * pStrip );

void hbDockAutoHideStripDestroy(
   HB_DOCK_AUTOHIDE_STRIP * pStrip );

#ifdef __cplusplus
}
#endif

#endif