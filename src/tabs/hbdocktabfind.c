#include "hbdocktabfind.h"

int hbDockTabFind(
      const HB_DOCK_TAB_GROUP * pGroup,
      const HB_DOCK_PANEL * pPanel )
{
   UINT i;

   for( i = 0;
        i < pGroup->Count;
        i++ )
   {
      if( pGroup->Tabs[ i ].pPanel == pPanel )
         return (int) i;
   }

   return -1;
}