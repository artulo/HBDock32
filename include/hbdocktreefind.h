#ifndef HBDOCKTREEFIND_H
#define HBDOCKTREEFIND_H

#include "hbdocklayouttree.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE * hbDockTreeFindPanel(
   HB_DOCK_LAYOUT_NODE * pRoot,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif