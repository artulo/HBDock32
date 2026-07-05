#ifndef HBDOCKTREE_H
#define HBDOCKTREE_H

#include <windows.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCK_NODE_LEAF = 0,
   HB_DOCK_NODE_SPLIT_H,
   HB_DOCK_NODE_SPLIT_V

} HB_DOCK_NODE_TYPE;

typedef struct _HB_DOCK_NODE HB_DOCK_NODE;

struct _HB_DOCK_NODE
{
   HB_DOCK_NODE_TYPE Type;

   HB_DOCK_NODE * Parent;
   HB_DOCK_NODE * First;
   HB_DOCK_NODE * Second;

   HB_DOCK_PANEL * Panel;

   RECT Rect;

   int SplitPos;
   int SplitterSize;
};

HB_DOCK_NODE * hbDockNodeNewLeaf(
   HB_DOCK_PANEL * pPanel );

HB_DOCK_NODE * hbDockNodeNewSplit(
   HB_DOCK_NODE_TYPE Type,
   HB_DOCK_NODE * pFirst,
   HB_DOCK_NODE * pSecond );

void hbDockNodeDelete(
   HB_DOCK_NODE * pNode );

void hbDockTreeLayout(
   HB_DOCK_NODE * pNode,
   const RECT * pRect );

HB_DOCK_PANEL * hbDockTreeHitTest(
   HB_DOCK_NODE * pNode,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif