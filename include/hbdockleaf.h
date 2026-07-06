#ifndef HBDOCKLEAF_H
#define HBDOCKLEAF_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockLeafCount(
   HB_DOCK_NODE * pRoot );

HB_DOCK_NODE * hbDockLeafFirst(
   HB_DOCK_NODE * pRoot );

HB_DOCK_NODE * hbDockLeafLast(
   HB_DOCK_NODE * pRoot );

#ifdef __cplusplus
}
#endif

#endif