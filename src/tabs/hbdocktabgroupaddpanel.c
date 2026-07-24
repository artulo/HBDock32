#include <windows.h>
#include <stdlib.h>
#include <string.h>

#include "hbdocktabgroup.h"

static BOOL hbDockTabGroupGrow(
   HB_DOCK_TAB_GROUP * pGroup )
{
   HB_DOCK_TAB * pTabs;
   UINT NewCapacity;

   if( pGroup == NULL )
      return FALSE;

   NewCapacity =
      pGroup->Capacity * 2;

   if( NewCapacity == 0 )
      NewCapacity = 8;

   pTabs =
      ( HB_DOCK_TAB * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_TAB ) *
         NewCapacity );

   if( pTabs == NULL )
      return FALSE;

   if( pGroup->Tabs != NULL )
   {
      memcpy(
         pTabs,
         pGroup->Tabs,
         sizeof( HB_DOCK_TAB ) *
         pGroup->Count );

      LocalFree(
         pGroup->Tabs );
   }

   pGroup->Tabs = pTabs;
   pGroup->Capacity = NewCapacity;

   return TRUE;
}

BOOL hbDockTabGroupAddPanel(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_TAB * pTab;

   if( pGroup == NULL )
      return FALSE;

   if( pPanel == NULL )
      return FALSE;

   if( pGroup->Count >= pGroup->Capacity )
   {
      if( !hbDockTabGroupGrow(
               pGroup ) )
         return FALSE;
   }

   pTab =
      &pGroup->Tabs[
         pGroup->Count ];

   ZeroMemory(
      pTab,
      sizeof( HB_DOCK_TAB ) );

   pTab->pPanel = pPanel;

#ifdef UNICODE

   lstrcpyn(
      pTab->Caption,
      TEXT("Panel"),
      127 );

#else

   lstrcpyn(
      pTab->Caption,
      "Panel",
      127 );

#endif

   pTab->UserData = 0;

   pGroup->Count++;

   if( pGroup->Count == 1 )
   {
      pGroup->ActiveIndex = 0;
      pGroup->pPanel = pPanel;
   }

   return TRUE;
}