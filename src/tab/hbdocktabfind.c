#include "hbdocktabfind.h"

int hbDockTabFind(
      const HB_DOCK_TAB_GROUP * pGroup,
      HWND hDock )
{
   UINT i;

   for( i = 0;
        i < pGroup->Count;
        i++ )
   {
      if( pGroup->Tabs[i].hDock ==
          hDock )
         return (int)i;
   }

   return -1;
}