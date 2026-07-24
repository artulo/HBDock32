#include "hbdockautohideslideposition.h"

void hbDockAutoHideSetSlidePosition(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nPos )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->SlidePosition = nPos;
}


int hbDockAutoHideGetSlidePosition(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->SlidePosition;
}