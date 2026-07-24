#ifndef HBDOCKLAYOUTREMOVEEMPTY_H
#define HBDOCKLAYOUTREMOVEEMPTY_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutRemoveEmpty(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pLeaf );

#ifdef __cplusplus
}
#endif

#endif