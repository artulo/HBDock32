#ifndef HBDOCKLAYOUTRELATIVE_H
#define HBDOCKLAYOUTRELATIVE_H

#include "hbdocklayouttree.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutInsertRelative(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_LAYOUT_NODE * pTarget,
   UINT Side );

#ifdef __cplusplus
}
#endif

#endif