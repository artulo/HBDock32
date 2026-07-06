#ifndef HBDOCKSPLITTERTRACKER_H
#define HBDOCKSPLITTERTRACKER_H

#include "hbdocksplitnode.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_SPLIT_NODE * Split;

   POINT StartPoint;

   int OriginalPos;

   int Tracking;

} HB_DOCK_SPLITTER_TRACKER;

void hbDockSplitterTrackerInit(
   HB_DOCK_SPLITTER_TRACKER * pTracker );

void hbDockSplitterTrackerBegin(
   HB_DOCK_SPLITTER_TRACKER * pTracker,
   HB_DOCK_SPLIT_NODE * pSplit,
   POINT pt );

void hbDockSplitterTrackerMove(
   HB_DOCK_SPLITTER_TRACKER * pTracker,
   POINT pt );

void hbDockSplitterTrackerEnd(
   HB_DOCK_SPLITTER_TRACKER * pTracker );

#ifdef __cplusplus
}
#endif

#endif