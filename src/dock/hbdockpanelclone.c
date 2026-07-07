#include <stdlib.h>
#include <string.h>

#include "hbdockpanelclone.h"

HB_DOCK_PANEL * hbDockPanelClone(
   const HB_DOCK_PANEL * pPanel )
{
   HB_DOCK_PANEL * pNew;

   if( pPanel == NULL )
      return NULL;

   pNew =
      ( HB_DOCK_PANEL * )
      calloc(
         1,
         sizeof( HB_DOCK_PANEL ) );

   if( pNew == NULL )
      return NULL;

   memcpy(
      pNew,
      pPanel,
      sizeof( HB_DOCK_PANEL ) );

   return pNew;
}

void hbDockPanelCopy(
   HB_DOCK_PANEL * pDest,
   const HB_DOCK_PANEL * pSource )
{
   if( pDest == NULL )
      return;

   if( pSource == NULL )
      return;

   memcpy(
      pDest,
      pSource,
      sizeof( HB_DOCK_PANEL ) );
}