#include <windows.h>

#include "hbdocktabselect.h"

BOOL hbDockTabSelect(
      HB_DOCK_TAB_GROUP * pGroup,
      UINT Index )
{
   UINT i;

   if( Index >= pGroup->Count )
      return FALSE;

   pGroup->ActiveIndex = Index;

   for( i = 0;
        i < pGroup->Count;
        i++ )
   {
      ShowWindow(
         pGroup->Tabs[i].hDock,
         i == Index ?
         SW_SHOW :
         SW_HIDE );
   }

   pGroup->hActiveDock =
      pGroup->Tabs[Index].hDock;

   return TRUE;
}