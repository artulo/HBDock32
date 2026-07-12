#include <windows.h>

#include "hbdocktabcontrol.h"

BOOL hbDockTabControlCreate(
    HB_DOCK_TAB_CONTROL * pControl,
    HWND hParent )
{
    ZeroMemory(
        pControl,
        sizeof(*pControl));

    pControl->Height = 24;
    pControl->HotIndex = -1;
    pControl->PressedIndex = -1;

    pControl->hWnd =
        CreateWindowEx(
            0,
            TEXT("HBTabControl"),
            NULL,
            WS_CHILD |
            WS_VISIBLE,
            0,
            0,
            100,
            24,
            hParent,
            NULL,
            GetModuleHandle(NULL),
            NULL);

    return
        pControl->hWnd != NULL;
}

void hbDockTabControlDestroy(
    HB_DOCK_TAB_CONTROL * pControl )
{
    if(pControl->hWnd)
        DestroyWindow(
            pControl->hWnd);
}