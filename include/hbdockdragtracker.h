#ifndef HBDOCKDRAGTRACKER_H
#define HBDOCKDRAGTRACKER_H

#include <windows.h>

#include "hbdockdragcontext.h"
#include "hbdockpreview.h"
#include "hbdockguides.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_DRAG_TRACKER
{
   HB_DOCK_DRAG_CONTEXT Context;

   HB_DOCK_GUIDES Guides;

   HB_DOCK_PREVIEW Preview;

} HB_DOCK_DRAG_TRACKER;

void hbDockDragTrackerInit(
   HB_DOCK_DRAG_TRACKER * pTracker );

void hbDockDragTrackerBegin(
   HB_DOCK_DRAG_TRACKER * pTracker,
   HB_DOCK_PANEL * pPanel,
   POINT pt );

void hbDockDragTrackerMove(
   HB_DOCK_DRAG_TRACKER * pTracker,
   HB_DOCK_NODE * pNode,
   POINT pt );

void hbDockDragTrackerEnd(
   HB_DOCK_DRAG_TRACKER * pTracker );

#ifdef __cplusplus
}
#endif

#endif