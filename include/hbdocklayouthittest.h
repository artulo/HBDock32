#ifndef HBDOCKLAYOUTHITTEST_H
#define HBDOCKLAYOUTHITTEST_H

#include <windows.h>

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE *
hbDockLayoutHitTest(
   HB_DOCK_LAYOUT_TREE * pTree,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif