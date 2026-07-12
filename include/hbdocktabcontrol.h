#ifndef HBDOCKTABCONTROL_H
#define HBDOCKTABCONTROL_H

#include <windows.h>
#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_TAB_CONTROL
{
    HWND hWnd;

    HB_DOCK_TAB_GROUP * pGroup;

    int Height;

    int FirstVisible;

    int HotIndex;

    int PressedIndex;

    HFONT hFont;

} HB_DOCK_TAB_CONTROL;

BOOL hbDockTabControlCreate(
    HB_DOCK_TAB_CONTROL * pControl,
    HWND hParent );

void hbDockTabControlDestroy(
    HB_DOCK_TAB_CONTROL * pControl );

#ifdef __cplusplus
}
#endif

#endif