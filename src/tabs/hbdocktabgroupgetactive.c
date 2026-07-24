#include <windows.h>

#include "hbdocktabgroup.h"

HB_DOCK_PANEL *
hbDockTabGroupGetActivePanel(
   const HB_DOCK_TAB_GROUP * pGroup )
{
   if( pGroup == NULL )
      return NULL;

   if( pGroup->Count == 0 )
      return NULL;

   return
      pGroup->Tabs[
         pGroup->ActiveIndex ].pPanel;
}