#include <windows.h>

#include "hbdockcontainermerge.h"
#include "hbdockcontaineraddtab.h"
#include "hbdockcontainer.h"


BOOL hbDockContainerMerge(
   HB_DOCK_CONTAINER * pTarget,
   HB_DOCK_CONTAINER * pSource )
{
   UINT i;


   if( pTarget == NULL )
      return FALSE;


   if( pSource == NULL )
      return FALSE;


   for( i = 0; i < pSource->TabGroup.Count; i++ )
   {
      if( pSource->TabGroup.Tabs[i].pPanel != NULL )
      {
         if( !hbDockContainerAddTab(
                pTarget,
                pSource->TabGroup.Tabs[i].pPanel ) )
         {
            return FALSE;
         }
      }
   }


   return TRUE;
}