#include <stdlib.h>
#include <string.h>

#include "hbdocktabadd.h"

BOOL hbDockTabAdd(
      HB_DOCK_TAB_GROUP * pGroup,
      HWND hDock,
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
         (HB_DOCK_TAB*)
         realloc(
            pGroup->Tabs,
            sizeof(HB_DOCK_TAB) *
            NewCapacity );

      if( pNew == NULL )
         return FALSE;

      pGroup->Tabs = pNew;
      pGroup->Capacity = NewCapacity;
   }

   pGroup->Tabs[
      pGroup->Count ].hDock = hDock;

   lstrcpy(
      pGroup->Tabs[
         pGroup->Count ].Caption,
      Caption );

   pGroup->Count++;

   return TRUE;
}