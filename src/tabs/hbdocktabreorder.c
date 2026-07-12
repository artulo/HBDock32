#include "hbdocktabreorder.h"

BOOL hbDockTabReorder(
      HB_DOCK_TAB_GROUP * pGroup,
      UINT OldIndex,
      UINT NewIndex )
{
   HB_DOCK_TAB Temp;
   UINT i;

   if( OldIndex >= pGroup->Count )
      return FALSE;

   if( NewIndex >= pGroup->Count )
      return FALSE;

   Temp =
      pGroup->Tabs[
         OldIndex ];

   if( OldIndex < NewIndex )
   {
      for( i = OldIndex;
           i < NewIndex;
           i++ )
      {
         pGroup->Tabs[i] =
            pGroup->Tabs[i+1];
      }
   }
   else
   {
      for( i = OldIndex;
           i > NewIndex;
           i-- )
      {
         pGroup->Tabs[i] =
            pGroup->Tabs[i-1];
      }
   }

   pGroup->Tabs[
      NewIndex ] = Temp;

   return TRUE;
}