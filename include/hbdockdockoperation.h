#ifndef HBDOCKDOCKOPERATION_H
#define HBDOCKDOCKOPERATION_H

#include "hbdocktree.h"
#include "hbdockdocksite.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_NODE * hbDockInsertPanel(
   HB_DOCK_NODE * pTarget,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site );

#ifdef __cplusplus
}
#endif

#endif