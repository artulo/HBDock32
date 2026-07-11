#include "hbdockautohideslidesize.h"

void hbDockAutoHideSetSlideSize(
   HB_DOCK_AUTOHIDE_PANE * pPane,
   int nSize )
{
   if( pPane != NULL )
      pPane->SlideSize = nSize;
}

int hbDockAutoHideGetSlideSize(
   const HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return 0;

   return pPane->SlideSize;
}