#ifndef HBDOCKLAYOUTNODECREATE_H
#define HBDOCKLAYOUTNODECREATE_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE *
hbDockLayoutCreateLeaf(
      HWND hDock );

HB_DOCK_LAYOUT_NODE *
hbDockLayoutCreateSplit(
      HB_LAYOUT_NODE_TYPE Type );

#ifdef __cplusplus
}
#endif

#endif