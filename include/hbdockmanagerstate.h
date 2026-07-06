#ifndef HBDOCKMANAGERSTATE_H
#define HBDOCKMANAGERSTATE_H

#include "hbdockhistory.h"
#include "hbdocklayoutengine.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_MANAGER_STATE
{
   HB_DOCK_LAYOUT_ENGINE Layout;

   HB_DOCK_HISTORY History;

   HB_DOCK_NODE * Root;

} HB_DOCK_MANAGER_STATE;

void hbDockManagerStateInit(
   HB_DOCK_MANAGER_STATE * pState );

void hbDockManagerStateClear(
   HB_DOCK_MANAGER_STATE * pState );

#ifdef __cplusplus
}
#endif

#endif