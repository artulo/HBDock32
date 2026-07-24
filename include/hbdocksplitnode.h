#ifndef HBDOCKSPLITNODE_H
#define HBDOCKSPLITNODE_H

#include <windows.h>

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_SPLIT_NODE
{
   HB_DOCK_LAYOUT_NODE * Node;

   RECT SplitterRect;

   int Tracking;

   int MinFirst;

   int MinSecond;

} HB_DOCK_SPLIT_NODE;

void hbDockSplitNodeInit(
   HB_DOCK_SPLIT_NODE * pSplit,
   HB_DOCK_LAYOUT_NODE * pNode );

void hbDockSplitNodeUpdate(
   HB_DOCK_SPLIT_NODE * pSplit );

int hbDockSplitNodeHitTest(
   const HB_DOCK_SPLIT_NODE * pSplit,
   POINT pt );

void hbDockSplitNodeMove(
   HB_DOCK_SPLIT_NODE * pSplit,
   int Delta );

#ifdef __cplusplus
}
#endif

#endif