#include "hbdockpaneldocksize.h"

void hbDockPanelSetDockSize(
   HB_DOCK_PANEL * pPanel,
   int cx,
   int cy )
{
   if( pPanel == NULL )
      return;

   pPanel->DockSize.cx = cx;
   pPanel->DockSize.cy = cy;
}

void hbDockPanelGetDockSize(
   const HB_DOCK_PANEL * pPanel,
   SIZE * pSize )
{
   if( pPanel == NULL || pSize == NULL )
      return;

   *pSize = pPanel->DockSize;
}