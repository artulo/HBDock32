#ifndef HBDOCKTREEINSERT_H
#define HBDOCKTREEINSERT_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_NODE * hbDockTreeInsertLeft(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_NODE * hbDockTreeInsertRight(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_NODE * hbDockTreeInsertTop(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_NODE * hbDockTreeInsertBottom(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif