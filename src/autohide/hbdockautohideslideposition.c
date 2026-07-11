#include "hbdockautohideslideposition.h"

void hbDockAutoHideSetSlidePosition(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nPos )
{
   if( pPane == NULL )
      return;

   pPane->SlidePosition = nPos;
}

int hbDockAutoHideGetSlidePosition(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->SlidePosition;
}