#include "hbdockautohidesliding.h"

void hbDockAutoHideBeginSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Sliding = 1;
}

void hbDockAutoHideEndSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane != NULL )
      pPane->Sliding = 0;
}

int hbDockAutoHideIsSliding(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->Sliding;
}