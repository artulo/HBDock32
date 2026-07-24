#ifndef HBDOCKTREEREMOVE_H
#define HBDOCKTREEREMOVE_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE * hbDockTreeRemoveNode(
   HB_DOCK_LAYOUT_NODE * pRoot,
   HB_DOCK_LAYOUT_NODE * pNode );

#ifdef __cplusplus
}
#endif

#endif