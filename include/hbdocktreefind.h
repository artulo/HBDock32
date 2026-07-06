#ifndef HBDOCKTREEFIND_H
#define HBDOCKTREEFIND_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_NODE * hbDockTreeFindPanel(
   HB_DOCK_NODE * pRoot,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif