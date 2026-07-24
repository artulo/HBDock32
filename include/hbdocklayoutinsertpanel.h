#ifndef HBDOCKLAYOUTINSERTPANEL_H
#define HBDOCKLAYOUTINSERTPANEL_H

#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"
#include "hbdockdocksite.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockLayoutInsertPanel(
   HB_DOCK_LAYOUT_TREE * pTree,
   HB_DOCK_LAYOUT_NODE * pTarget,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_SITE Site );

#ifdef __cplusplus
}
#endif

#endif