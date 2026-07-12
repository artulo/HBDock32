#include <windows.h>

#include "hbdocktabmouse.h"
#include "hbdocktabhittest.h"
#include "hbdocktabselect.h"

void hbDockTabMouseDown(
    HB_DOCK_TAB_CONTROL * pControl,
    POINT pt )
{
    pControl->PressedIndex =
        hbDockTabHitTest(
            pControl,
            pt );
}

void hbDockTabMouseMove(
    HB_DOCK_TAB_CONTROL * pControl,
    POINT pt )
{
    pControl->HotIndex =
        hbDockTabHitTest(
            pControl,
            pt );
}

void hbDockTabMouseUp(
    HB_DOCK_TAB_CONTROL * pControl,
    POINT pt )
{
    int index;

    index =
        hbDockTabHitTest(
            pControl,
            pt );

    if(index==pControl->PressedIndex &&
       index!=-1)
    {
        hbDockTabSelect(
            pControl->pGroup,
            index );
    }

    pControl->PressedIndex=-1;
}