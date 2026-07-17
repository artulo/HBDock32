#ifndef HBDOCKLAYOUTTREE_H
#define HBDOCKLAYOUTTREE_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_CONTAINER HB_DOCK_CONTAINER;

typedef enum
{
   HB_LAYOUT_LEAF = 0,
   HB_LAYOUT_HORIZONTAL,
   HB_LAYOUT_VERTICAL

} HB_LAYOUT_NODE_TYPE;

typedef struct _HB_DOCK_LAYOUT_NODE
{
   HB_LAYOUT_NODE_TYPE Type;

   RECT Rect;

   float Ratio;

   //HWND hDockWindow;
   HB_DOCK_CONTAINER * pContainer;	
   struct _HB_DOCK_LAYOUT_NODE * Parent;
   struct _HB_DOCK_LAYOUT_NODE * First;
   struct _HB_DOCK_LAYOUT_NODE * Second;

} HB_DOCK_LAYOUT_NODE;

typedef struct
{
   HB_DOCK_LAYOUT_NODE * Root;

} HB_DOCK_LAYOUT_TREE;

BOOL hbDockLayoutTreeInit(
      HB_DOCK_LAYOUT_TREE * pTree );

void hbDockLayoutTreeDone(
      HB_DOCK_LAYOUT_TREE * pTree );

#ifdef __cplusplus
}
#endif

#endif