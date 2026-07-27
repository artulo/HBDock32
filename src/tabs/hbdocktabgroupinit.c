#include <windows.h>

#include "hbdocktabgroup.h"

#define HB_DOCK_TABGROUP_INITIAL_CAPACITY 8

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
