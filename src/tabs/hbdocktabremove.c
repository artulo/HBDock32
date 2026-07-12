#include <string.h>

#include "hbdocktabremove.h"

BOOL hbDockTabRemove(
      HB_DOCK_TAB_GROUP * pGroup,
      UINT Index )
{
   UINT i;

   if( Index >= pGroup->Count )
      return FALSE;

   for( i = Index;
        i < pGroup->Count - 1;
        i++ )
   {
      pGroup->Tabs[i] =
         pGroup->Tabs[i+1];
   }

   pGroup->Count--;

   if( pGroup->ActiveIndex >=
       pGroup->Count )
      pGroup->ActiveIndex =
         pGroup->Count ?
         pGroup->Count - 1 :
         0;

   return TRUE;
}