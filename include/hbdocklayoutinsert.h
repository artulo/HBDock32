#ifndef HBDOCKLAYOUTINSERT_H
#define HBDOCKLAYOUTINSERT_H

#include "hbdocklayouttree.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutInsertPanel(
      HB_DOCK_LAYOUT_TREE * pTree,
      HB_DOCK_PANEL * pPanel,
      UINT Side );
	  
BOOL hbDockLayoutInsertRoot(
      HB_DOCK_LAYOUT_TREE * pTree,
     HB_DOCK_CONTAINER * pContainer );

BOOL hbDockLayoutSplitLeaf(
      HB_DOCK_LAYOUT_NODE * pLeaf,
      HB_DOCK_CONTAINER * pNewContainer,
      HB_LAYOUT_NODE_TYPE SplitType );

#ifdef __cplusplus
}
#endif

#endif