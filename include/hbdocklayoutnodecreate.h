#ifndef HBDOCKLAYOUTNODECREATE_H
#define HBDOCKLAYOUTNODECREATE_H

#include "hbdocklayouttree.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif


HB_DOCK_LAYOUT_NODE * hbDockLayoutNodeCreateLeaf(
   HB_DOCK_PANEL * pPanel );


HB_DOCK_LAYOUT_NODE * hbDockLayoutNodeCreateSplit(
   HB_LAYOUT_NODE_TYPE Type,
   HB_DOCK_LAYOUT_NODE * pFirst,
   HB_DOCK_LAYOUT_NODE * pSecond );


#ifdef __cplusplus
}
#endif

#endif /* HBDOCKLAYOUTNODECREATE_H */