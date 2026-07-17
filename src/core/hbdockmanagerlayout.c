#include "hbdockmanagerlayout.h"
#include "hbdocklayoutrecalc.h"

void hbDockManagerUpdateLayout(
      HB_DOCK_MANAGER * pManager )
{
    RECT rc;

    if( pManager == NULL )
        return;

    GetClientRect(
        pManager->hMainWnd,
        &rc );

    hbDockLayoutRecalc(
        &pManager->LayoutTree,
        rc );
}