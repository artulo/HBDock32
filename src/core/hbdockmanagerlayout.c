#include "hbdockmanagerlayout.h"

void hbDockManagerUpdateLayout(
      HB_DOCK_MANAGER * pManager )
{
    if( pManager->UpdatingLayout )
        return;

    pManager->UpdatingLayout = TRUE;

    hbDockLayoutTreeRecalc(
        &pManager->LayoutTree );

    pManager->UpdatingLayout = FALSE;
}