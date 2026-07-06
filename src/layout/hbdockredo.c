#include "hbdockredo.h"

void hbDockRedoInit(
   HB_DOCK_REDO * pRedo )
{
   hbDockUndoInit(
      pRedo );
}

void hbDockRedoPush(
   HB_DOCK_REDO * pRedo,
   HB_DOCK_NODE * pRoot )
{
   hbDockUndoPush(
      pRedo,
      pRoot );
}

HB_DOCK_NODE * hbDockRedoPop(
   HB_DOCK_REDO * pRedo )
{
   return hbDockUndoPop(
      pRedo );
}