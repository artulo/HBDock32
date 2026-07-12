#include "hbdockguidehighlight.h"

void hbDockGuideHighlight(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide )
      pGuide->Hot = TRUE;
}

void hbDockGuideUnHighlight(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide )
      pGuide->Hot = FALSE;
}