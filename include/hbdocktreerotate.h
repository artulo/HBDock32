#ifndef HBDOCKTREEROTATE_H
#define HBDOCKTREEROTATE_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_NODE * hbDockTreeRotateLeft(
   HB_DOCK_NODE * pNode );

HB_DOCK_NODE * hbDockTreeRotateRight(
   HB_DOCK_NODE * pNode );

#ifdef __cplusplus
}
#endif

#endif