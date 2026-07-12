#include "hbdocktabhittest.h"

#define TAB_WIDTH 120

int hbDockTabHitTest(
    HB_DOCK_TAB_CONTROL * pControl,
    POINT pt )
{
    int index;

    index =
        pt.x /
        TAB_WIDTH;

    if(index>=0 &&
       index<(int)pControl->pGroup->Count)
        return index;

    return -1;
}