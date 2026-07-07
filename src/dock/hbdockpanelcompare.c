#include <string.h>

#include "hbdockpanelcompare.h"

int hbDockPanelCompareId(
   const HB_DOCK_PANEL * p1,
   const HB_DOCK_PANEL * p2 )
{
   if( p1 == p2 )
      return 1;

   if( p1 == NULL || p2 == NULL )
      return 0;

   return p1->Id == p2->Id;
}

int hbDockPanelCompareName(
   const HB_DOCK_PANEL * p1,
   const HB_DOCK_PANEL * p2 )
{
   if( p1 == p2 )
      return 1;

   if( p1 == NULL || p2 == NULL )
      return 0;

   return strcmp(
      p1->Name,
      p2->Name ) == 0;
}