#ifndef HBDOCKLAYOUTMUTATION_H
#define HBDOCKLAYOUTMUTATION_H

#include "hbdocklayouttree.h"


#ifdef __cplusplus
extern "C" {
#endif


BOOL hbDockLayoutRemoveNode(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pNode );


BOOL hbDockLayoutReplace(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pOld,
   HB_DOCK_LAYOUT_NODE * pNew );


#ifdef __cplusplus
}
#endif


#endif