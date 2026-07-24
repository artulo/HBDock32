#include <stdlib.h>
#include <string.h>

#include "hbdocktabadd.h"

BOOL hbDockTabAdd(
      HB_DOCK_TAB_GROUP * pGroup,
      HB_DOCK_PANEL * pPanel,
      LPCTSTR Caption )
{
   if( pGroup->Count == pGroup->Capacity )
   {
      UINT NewCapacity =
         pGroup->Capacity == 0 ?
         8 :
         pGroup->Capacity * 2;

      HB_DOCK_TAB * pNew;

      pNew =
         (HB_DOCK_TAB *)
         realloc(
            pGroup->Tabs,
            sizeof( HB_DOCK_TAB ) * NewCapacity );

      if( pNew == NULL )
         return FALSE;

      pGroup->Tabs = pNew;
      pGroup->Capacity = NewCapacity;
   }

   pGroup->Tabs[ pGroup->Count ].pPanel = pPanel;

   lstrcpy(
      pGroup->Tabs[ pGroup->Count ].Caption,
      Caption );

   pGroup->Tabs[ pGroup->Count ].UserData = 0;

   pGroup->Count++;

   return TRUE;
}