#include "hbdockcontainermerge.h"
#include "hbdockcontaineraddtab.h"

BOOL hbDockContainerMerge(
      HB_DOCK_CONTAINER * pDestination,
      HB_DOCK_CONTAINER * pSource )
{
   UINT i;

   if( pDestination == NULL )
      return FALSE;

   if( pSource == NULL )
      return FALSE;

   for(i=0;
       i<pSource->TabGroup.Count;
       i++)
   {
      hbDockContainerAddTab(
         pDestination,
         pSource->TabGroup.Tabs[i].hDock,
         pSource->TabGroup.Tabs[i].Caption);
   }

   return TRUE;
}