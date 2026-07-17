#ifndef HBDOCKLAYOUTFIND_H
#define HBDOCKLAYOUTFIND_H

#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE *
hbDockLayoutFindContainer(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_CONTAINER * pContainer );

HB_DOCK_LAYOUT_NODE *
hbDockLayoutFindPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif