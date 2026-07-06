#include "hbdockpanelmanager.h"

void hbDockPanelManagerInit(
   HB_DOCK_PANEL_MANAGER * pManager )
{
   hbDockArrayInit(
      &pManager->Panels );
}

void hbDockPanelManagerDestroy(
   HB_DOCK_PANEL_MANAGER * pManager )
{
   hbDockArrayRelease(
      &pManager->Panels );
}

int hbDockPanelManagerAdd(
   HB_DOCK_PANEL_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   return hbDockArrayAdd(
      &pManager->Panels,
      pPanel );
}

int hbDockPanelManagerRemove(
   HB_DOCK_PANEL_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel )
{
   int i;

   for( i = 0;
        i < pManager->Panels.Count;
        i++ )
   {
      if( hbDockArrayGet(
             &pManager->Panels,
             i ) == pPanel )
         return hbDockArrayRemove(
            &pManager->Panels,
            i );
   }

   return 0;
}

HB_DOCK_PANEL * hbDockPanelManagerGet(
   HB_DOCK_PANEL_MANAGER * pManager,
   int Index )
{
   return ( HB_DOCK_PANEL * )
      hbDockArrayGet(
         &pManager->Panels,
         Index );
}