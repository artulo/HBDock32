#ifndef HBDOCKLAYOUTDESTROY_H
#define HBDOCKLAYOUTDESTROY_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif


void hbDockLayoutDestroyNode(
   HB_DOCK_LAYOUT_NODE * pNode );


void hbDockLayoutDestroyTree(
   HB_DOCK_LAYOUT_TREE * pTree );


#ifdef __cplusplus
}
#endif

#endif