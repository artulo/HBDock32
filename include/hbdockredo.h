#ifndef HBDOCKREDO_H
#define HBDOCKREDO_H

#include "hbdockundo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef HB_DOCK_UNDO HB_DOCK_REDO;

void hbDockRedoInit(
   HB_DOCK_REDO * pRedo );

void hbDockRedoPush(
   HB_DOCK_REDO * pRedo,
   HB_DOCK_NODE * pRoot );

HB_DOCK_NODE * hbDockRedoPop(
   HB_DOCK_REDO * pRedo );

#ifdef __cplusplus
}
#endif

#endif