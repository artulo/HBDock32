#include <windows.h>
#include <stdlib.h>
#include <string.h>

#include "hbdocktabgroup.h"


#define HB_DOCK_TABGROUP_INITIAL_CAPACITY 8


static BOOL hbDockTabGroupGrow(
   HB_DOCK_TAB_GROUP * pGroup )
{
   HB_DOCK_TAB * pNew;
   UINT NewCapacity;


   NewCapacity =
      pGroup->Capacity * 2;


   pNew =
      ( HB_DOCK_TAB * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_TAB ) *
         NewCapacity );


   if( pNew == NULL )
      return FALSE;


   if( pGroup->Tabs != NULL &&
       pGroup->Count > 0 )
   {
      CopyMemory(
         pNew,
         pGroup->Tabs,
         sizeof( HB_DOCK_TAB ) *
         pGroup->Count );
   }


   if( pGroup->Tabs != NULL )
      LocalFree(
         pGroup->Tabs );


   pGroup->Tabs = pNew;

   pGroup->Capacity =
      NewCapacity;


   return TRUE;
}



BOOL hbDockTabGroupInit(
   HB_DOCK_TAB_GROUP * pGroup )
{
   if( pGroup == NULL )
      return FALSE;


   ZeroMemory(
      pGroup,
      sizeof( HB_DOCK_TAB_GROUP ) );


   pGroup->Capacity =
      HB_DOCK_TABGROUP_INITIAL_CAPACITY;


   pGroup->Tabs =
      ( HB_DOCK_TAB * )
      LocalAlloc(
         LPTR,
         sizeof( HB_DOCK_TAB ) *
         pGroup->Capacity );


   if( pGroup->Tabs == NULL )
      return FALSE;


   return TRUE;
}



void hbDockTabGroupDone(
   HB_DOCK_TAB_GROUP * pGroup )
{
   if( pGroup == NULL )
      return;


   if( pGroup->Tabs != NULL )
   {
      LocalFree(
         pGroup->Tabs );

      pGroup->Tabs = NULL;
   }


   ZeroMemory(
      pGroup,
      sizeof( HB_DOCK_TAB_GROUP ) );
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
      {
         return FALSE;
      }
   }


   pTab =
      &pGroup->Tabs[
          pGroup->Count ];


   ZeroMemory(
      pTab,
      sizeof( HB_DOCK_TAB ) );


   pTab->pPanel =
      pPanel;


   pGroup->Count++;


   if( pGroup->Count == 1 )
   {
      pGroup->ActiveIndex = 0;
      pGroup->pPanel = pPanel;
   }


   return TRUE;
}



BOOL hbDockTabGroupRemovePanel(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel )
{
   UINT i;


   if( pGroup == NULL )
      return FALSE;


   if( pPanel == NULL )
      return FALSE;


   for( i = 0; i < pGroup->Count; i++ )
   {
      if( pGroup->Tabs[i].pPanel == pPanel )
      {
         break;
      }
   }


   if( i >= pGroup->Count )
      return FALSE;



   for( ;
        i < pGroup->Count - 1;
        i++ )
   {
      pGroup->Tabs[i] =
         pGroup->Tabs[i+1];
   }


   pGroup->Count--;


   if( pGroup->ActiveIndex >= pGroup->Count )
      pGroup->ActiveIndex =
         0;


   if( pGroup->Count > 0 )
      pGroup->pPanel =
         pGroup->Tabs[
            pGroup->ActiveIndex ].pPanel;
   else
      pGroup->pPanel = NULL;


   return TRUE;
}



HB_DOCK_PANEL * hbDockTabGroupGetActivePanel(
   const HB_DOCK_TAB_GROUP * pGroup )
{
   if( pGroup == NULL )
      return NULL;


   if( pGroup->Count == 0 )
      return NULL;


   return pGroup->Tabs[
      pGroup->ActiveIndex ].pPanel;
}



BOOL hbDockTabGroupSetActive(
   HB_DOCK_TAB_GROUP * pGroup,
   UINT Index )
{
   if( pGroup == NULL )
      return FALSE;


   if( Index >= pGroup->Count )
      return FALSE;


   pGroup->ActiveIndex =
      Index;


   pGroup->pPanel =
      pGroup->Tabs[Index].pPanel;


   return TRUE;
}