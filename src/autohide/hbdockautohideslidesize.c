#include "hbdockautohideslidesize.h"

void hbDockAutoHideSetSlideSize(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int nSize )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->SlideSize = nSize;
}


int hbDockAutoHideGetSlideSize(
   const HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return 0;

   return pAutoHide->SlideSize;
}