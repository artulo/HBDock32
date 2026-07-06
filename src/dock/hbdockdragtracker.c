#include <windows.h>

#include "hbdockdragtracker.h"

void hbDockDragTrackerInit(
   HB_DOCK_DRAG_TRACKER * pTracker )
{
   hbDockDragContextInit(
      &pTracker->Context );

   hbDockGuidesInit(
      &pTracker->Guides );

   hbDockPreviewInit(
      &pTracker->Preview );
}

void hbDockDragTrackerBegin(
   HB_DOCK_DRAG_TRACKER * pTracker,
   HB_DOCK_PANEL * pPanel,
   POINT pt )
{
   hbDockDragContextBegin(
      &pTracker->Context,
      pPanel,
      pt );
}

void hbDockDragTrackerMove(
   HB_DOCK_DRAG_TRACKER * pTracker,
   HB_DOCK_NODE * pNode,
   POINT pt )
{
   HB_DOCK_SITE Site;

   hbDockDragContextMove(
      &pTracker->Context,
      pt );

   hbDockGuidesBuild(
      &pTracker->Guides,
      pNode );

   Site =
      hbDockGuidesHitTest(
         &pTracker->Guides,
         pt );

   pTracker->Context.CurrentSite = Site;

   if( Site != HB_DOCKSITE_NONE )
   {
      hbDockSiteCalc(
         &pTracker->Guides.Guide[
            Site - 1 ],
         pNode,
         Site );

      hbDockPreviewShow(
         &pTracker->Preview,
         &pTracker->Guides.Guide[
            Site - 1 ].Rect );
   }
   else
      hbDockPreviewHide(
         &pTracker->Preview );
}

void hbDockDragTrackerEnd(
   HB_DOCK_DRAG_TRACKER * pTracker )
{
   hbDockPreviewHide(
      &pTracker->Preview );

   hbDockDragContextEnd(
      &pTracker->Context );
}