#ifndef HBDOCKLAYOUTCOPY_H
#define HBDOCKLAYOUTCOPY_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE * hbDockLayoutCopyNode(
   const HB_DOCK_LAYOUT_NODE * pSource,
   HB_DOCK_LAYOUT_NODE * pParent );

#ifdef __cplusplus
}
#endif

#endif