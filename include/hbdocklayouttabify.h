#ifndef HBDOCKLAYOUTTABIFY_H
#define HBDOCKLAYOUTTABIFY_H

#include "hbdocklayouttree.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif


BOOL hbDockLayoutTabifyPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_PANEL * pSource,
   HB_DOCK_PANEL * pTarget );


#ifdef __cplusplus
}
#endif

#endif