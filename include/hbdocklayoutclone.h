#ifndef HBDOCKLAYOUTCLONE_H
#define HBDOCKLAYOUTCLONE_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif


BOOL hbDockLayoutCloneTree(
   const HB_DOCK_LAYOUT_TREE * pSource,
   HB_DOCK_LAYOUT_TREE * pDest );


HB_DOCK_LAYOUT_NODE * hbDockLayoutCloneNode(
   const HB_DOCK_LAYOUT_NODE * pNode );


#ifdef __cplusplus
}
#endif


#endif