#include <windows.h>

#include "hbdocktabpaint.h"

#define TAB_WIDTH 120

void hbDockTabPaint(
    HB_DOCK_TAB_CONTROL * pControl,
    HDC hDC )
{
    UINT i;

    RECT rc;

    SetBkMode(
        hDC,
        TRANSPARENT );

    for(i=0;i<pControl->pGroup->Count;i++)
    {
        rc.left=i*TAB_WIDTH;

        rc.right=rc.left+TAB_WIDTH;

        rc.top=0;

        rc.bottom=pControl->Height;

        FillRect(
            hDC,
            &rc,
            (HBRUSH)(COLOR_BTNFACE+1));

        Rectangle(
            hDC,
            rc.left,
            rc.top,
            rc.right,
            rc.bottom);

        DrawText(
            hDC,
            pControl->pGroup->Tabs[i].Caption,
            -1,
            &rc,
            DT_CENTER|
            DT_VCENTER|
            DT_SINGLELINE);
    }
}