#ifndef HBDOCKSPLITTER_H
#define HBDOCKSPLITTER_H

#include <windows.h>

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_SPLITTER
{
   HB_DOCK_LAYOUT_NODE * pNode;

   RECT Rect;

   BOOL Tracking;

   int Size;

} HB_DOCK_SPLITTER;

BOOL hbDockSplitterBuild(
      HB_DOCK_LAYOUT_NODE * pNode,
      HB_DOCK_SPLITTER * pSplitter );

#ifdef __cplusplus
}
#endif

#endif