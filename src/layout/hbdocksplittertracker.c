#include "hbdocksplittertracker.h"

void hbDockSplitterTrackerInit(
   HB_DOCK_SPLITTER_TRACKER * pTracker )
{
   ZeroMemory(
      pTracker,
      sizeof( HB_DOCK_SPLITTER_TRACKER ) );
}

void hbDockSplitterTrackerBegin(
   HB_DOCK_SPLITTER_TRACKER * pTracker,
   HB_DOCK_SPLIT_NODE * pSplit,
   POINT pt )
{
   pTracker->Split = pSplit;
   pTracker->StartPoint = pt;
   pTracker->OriginalPos =
      pSplit->Node->SplitPos;
   pTracker->Tracking = 1;
}

void hbDockSplitterTrackerMove(
   HB_DOCK_SPLITTER_TRACKER * pTracker,
   POINT pt )
{
   int Delta;

   if( !pTracker->Tracking )
      return;

   if( pTracker->Split->Node->Type ==
       HB_DOCK_NODE_SPLIT_H )
      Delta = pt.x -
         pTracker->StartPoint.x;
   else
      Delta = pt.y -
         pTracker->StartPoint.y;

   hbDockSplitNodeMove(
      pTracker->Split,
      Delta );
}

void hbDockSplitterTrackerEnd(
   HB_DOCK_SPLITTER_TRACKER * pTracker )
{
   pTracker->Tracking = 0;
   pTracker->Split = NULL;
}