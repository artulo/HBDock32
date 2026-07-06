#include <string.h>

#include "hbdocktabgroup.h"

void hbDockTabGroupInit(
   HB_DOCK_TAB_GROUP * pGroup )
{
   if( pGroup == NULL )
      return;

   ZeroMemory(
      pGroup,
      sizeof( HB_DOCK_TAB_GROUP ) );

   pGroup->Active = -1;
}

int hbDockTabGroupAdd(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel )
{
   if( pGroup == NULL )
      return 0;

   if( pGroup->Count >= HB_DOCK_MAX_TABS )
      return 0;

   pGroup->Panels[ pGroup->Count ] = pPanel;

   if( pGroup->Active < 0 )
      pGroup->Active = 0;

   pGroup->Count++;

   return 1;
}

int hbDockTabGroupRemove(
   HB_DOCK_TAB_GROUP * pGroup,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   if( pGroup == NULL )
      return 0;

   for( i = 0; i < pGroup->Count; i++ )
   {
      if( pGroup->Panels[ i ] == pPanel )
      {
         memmove(
            &pGroup->Panels[ i ],
            &pGroup->Panels[ i + 1 ],
            ( pGroup->Count - i - 1 ) *
            sizeof( HB_DOCK_PANEL * ) );

         pGroup->Count--;

         if( pGroup->Active >= pGroup->Count )
            pGroup->Active = pGroup->Count - 1;

         return 1;
      }
   }

   return 0;
}

HB_DOCK_PANEL * hbDockTabGroupGetActive(
   HB_DOCK_TAB_GROUP * pGroup )
{
   if( pGroup == NULL )
      return NULL;

   if( pGroup->Active < 0 )
      return NULL;

   if( pGroup->Active >= pGroup->Count )
      return NULL;

   return pGroup->Panels[
      pGroup->Active ];
}

void hbDockTabGroupSetActive(
   HB_DOCK_TAB_GROUP * pGroup,
   int Index )
{
   if( pGroup == NULL )
      return;

   if( Index < 0 )
      return;

   if( Index >= pGroup->Count )
      return;

   pGroup->Active = Index;
}