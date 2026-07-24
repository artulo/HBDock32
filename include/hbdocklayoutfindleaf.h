#ifndef HBDOCKLAYOUTFINDLEAF_H
#define HBDOCKLAYOUTFINDLEAF_H

#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE * hbDockLayoutFindLeaf(
   HB_DOCK_LAYOUT_NODE * pNode,
   HB_DOCK_CONTAINER * pContainer );

#ifdef __cplusplus
}
#endif

#endif