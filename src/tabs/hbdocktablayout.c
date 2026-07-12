#include "hbdocktablayout.h"

void hbDockTabLayout(
    HB_DOCK_TAB_CONTROL * pControl,
    RECT rcClient )
{
    MoveWindow(
        pControl->hWnd,
        rcClient.left,
        rcClient.top,
        rcClient.right - rcClient.left,
        pControl->Height,
        TRUE );
}