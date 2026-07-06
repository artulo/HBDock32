#ifndef HBDOCKUNDO_H
#define HBDOCKUNDO_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_UNDO_LEVELS 32

typedef struct
{
   HB_DOCK_NODE * States[
      HB_DOCK_UNDO_LEVELS ];

   int Count;

} HB_DOCK_UNDO;

void hbDockUndoInit(
   HB_DOCK_UNDO * pUndo );

void hbDockUndoPush(
   HB_DOCK_UNDO * pUndo,
   HB_DOCK_NODE * pRoot );

HB_DOCK_NODE * hbDockUndoPop(
   HB_DOCK_UNDO * pUndo );

#ifdef __cplusplus
}
#endif

#endif