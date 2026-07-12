#ifndef HBDOCKLAYOUTINSERT_H
#define HBDOCKLAYOUTINSERT_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutInsertRoot(
      HB_DOCK_LAYOUT_TREE * pTree,
      HWND hDock );

BOOL hbDockLayoutSplitLeaf(
      HB_DOCK_LAYOUT_NODE * pLeaf,
      HWND hNewDock,
      HB_LAYOUT_NODE_TYPE SplitType );

#ifdef __cplusplus
}
#endif

#endif