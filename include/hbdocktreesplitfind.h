#ifndef HBDOCKTREESPLITFIND_H
#define HBDOCKTREESPLITFIND_H

#include <windows.h>

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE * hbDockTreeFindSplitterAt(
   HB_DOCK_LAYOUT_NODE * pNode,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif