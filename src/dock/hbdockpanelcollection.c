#include "hbdockpanelcollection.h"
#include "hbdockarray.h"

void hbDockPanelCollectionInit(
   HB_DOCK_PANEL_COLLECTION * pCollection )
{
   hbDockArrayInit(
      &pCollection->Items );
}

void hbDockPanelCollectionRelease(
   HB_DOCK_PANEL_COLLECTION * pCollection )
{
   if( pCollection == NULL )
      return;

   hbDockArrayDestroy(
      &pCollection->Items );
}

int hbDockPanelCollectionAdd(
   HB_DOCK_PANEL_COLLECTION * pCollection,
   HB_DOCK_PANEL * pPanel )
{
   return hbDockArrayAdd(
      &pCollection->Items,
      pPanel );
}

HB_DOCK_PANEL * hbDockPanelCollectionGet(
   HB_DOCK_PANEL_COLLECTION * pCollection,
   int Index )
{
   return ( HB_DOCK_PANEL * )
      hbDockArrayGet(
         &pCollection->Items,
         Index );
}

int hbDockPanelCollectionCount(
   const HB_DOCK_PANEL_COLLECTION * pCollection )
{
   return pCollection->Items.Count;
}