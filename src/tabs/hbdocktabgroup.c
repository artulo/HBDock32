#include <windows.h>
#include <stdlib.h>
#include <string.h>

#include "hbdocktabgroup.h"


#define HB_DOCK_TABGROUP_INITIAL_CAPACITY 8



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