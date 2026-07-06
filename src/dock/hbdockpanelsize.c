#include "hbdockpanelsize.h"

void hbDockPanelSetMinSize(
   HB_DOCK_PANEL * pPanel,
   int cx,
   int cy )
{
   if( pPanel == NULL )
      return;

   pPanel->MinSize.cx = cx;
   pPanel->MinSize.cy = cy;
}

void hbDockPanelSetMaxSize(
   HB_DOCK_PANEL * pPanel,
   int cx,
   int cy )
{
   if( pPanel == NULL )
      return;

   pPanel->MaxSize.cx = cx;
   pPanel->MaxSize.cy = cy;
}

void hbDockPanelGetMinSize(
   const HB_DOCK_PANEL * pPanel,
   SIZE * pSize )
{
   if( pPanel == NULL || pSize == NULL )
      return;

   *pSize = pPanel->MinSize;
}

void hbDockPanelGetMaxSize(
   const HB_DOCK_PANEL * pPanel,
   SIZE * pSize )
{
   if( pPanel == NULL || pSize == NULL )
      return;

   *pSize = pPanel->MaxSize;
}