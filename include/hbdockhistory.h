#ifndef HBDOCKHISTORY_H
#define HBDOCKHISTORY_H

#include "hbdockundo.h"
#include "hbdockredo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_HISTORY
{
   HB_DOCK_UNDO Undo;
   HB_DOCK_REDO Redo;

} HB_DOCK_HISTORY;

void hbDockHistoryInit(
   HB_DOCK_HISTORY * pHistory );

void hbDockHistorySave(
   HB_DOCK_HISTORY * pHistory,
   HB_DOCK_NODE * pRoot );

HB_DOCK_NODE * hbDockHistoryUndo(
   HB_DOCK_HISTORY * pHistory,
   HB_DOCK_NODE * pCurrent );

HB_DOCK_NODE * hbDockHistoryRedo(
   HB_DOCK_HISTORY * pHistory,
   HB_DOCK_NODE * pCurrent );

#ifdef __cplusplus
}
#endif

#endif