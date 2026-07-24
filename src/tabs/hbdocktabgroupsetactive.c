#include <windows.h>

#include "hbdocktabgroup.h"

BOOL hbDockTabGroupSetActive(
   HB_DOCK_TAB_GROUP * pGroup,
   UINT Index )
{
   if( pGroup == NULL )
      return FALSE;

   if( Index >= pGroup->Count )
      return FALSE;

   pGroup->ActiveIndex = Index;

   pGroup->pPanel =
      pGroup->Tabs[
         Index ].pPanel;

   return TRUE;
}