#ifndef HBDOCKLAYOUTINSERTNODE_H
#define HBDOCKLAYOUTINSERTNODE_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutInsertNode(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pNode,
   UINT Side );

#ifdef __cplusplus
}
#endif

#endif