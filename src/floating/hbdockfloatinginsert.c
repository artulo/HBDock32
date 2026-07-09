#include "hbdockfloatinginsert.h"

int hbDockFloatingInsert(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int Index,
   HB_DOCK_FLOATING_FRAME * pFrame )
{
   return hbDockArrayInsert(
      &pManager->Frames,
      Index,
      pFrame );
}