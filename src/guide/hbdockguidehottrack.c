#include "hbdockguidehottrack.h"

void hbDockGuideSetHot(
   HB_DOCK_GUIDE * pGuide,
   BOOL Hot )
{
   if( pGuide == NULL )
      return;

   pGuide->Hot = Hot;
}

BOOL hbDockGuideIsHot(
   const HB_DOCK_GUIDE * pGuide )
{
   if( pGuide == NULL )
      return FALSE;

   return pGuide->Hot;
}