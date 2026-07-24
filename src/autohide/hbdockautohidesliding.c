#include "hbdockautohidesliding.h"

void hbDockAutoHideBeginSlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Sliding = 1;
}


void hbDockAutoHideEndSlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide != NULL )
      pAutoHide->Sliding = 0;
}


int hbDockAutoHideIsSliding(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->Sliding;
}