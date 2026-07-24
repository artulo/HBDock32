#include <windows.h>

#include "hbdocktabgroup.h"

BOOL hbDockTabGroupRemovePanel(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel )
{
   UINT i;
   UINT Index;

   if( pGroup == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   Index = ( UINT ) -1;

   for( i = 0; i < pGroup->Count; ++i )
   {
      if( pGroup->Tabs[ i ].pPanel == pPanel )
      {
         Index = i;
         break;
      }
   }

   if( Index == ( UINT ) -1 )
      return FALSE;

   for( i = Index; i + 1 < pGroup->Count; ++i )
   {
      pGroup->Tabs[ i ] =
         pGroup->Tabs[ i + 1 ];
   }

   pGroup->Count--;

   if( pGroup->Count == 0 )
   {
      pGroup->ActiveIndex = 0;
      pGroup->pPanel = NULL;
      return TRUE;
   }

   if( pGroup->ActiveIndex >= pGroup->Count )
      pGroup->ActiveIndex =
         pGroup->Count - 1;

   pGroup->pPanel =
      pGroup->Tabs[
         pGroup->ActiveIndex ].pPanel;

   return TRUE;
}