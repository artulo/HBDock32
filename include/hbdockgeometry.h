#ifndef HBDOCKGEOMETRY_H
#define HBDOCKGEOMETRY_H

#include <windows.h>
#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    RECT Bounds;
    RECT Client;
    RECT Tabs;
    RECT Splitter;

} HB_DOCK_GEOMETRY;

BOOL hbDockGeometryCalculate(
        HB_DOCK_LAYOUT_TREE * pTree,
        const RECT * pClient );

BOOL hbDockGeometryNode(
        HB_DOCK_LAYOUT_NODE * pNode,
        const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif