#ifndef HBDOCKFLOATINGINSERT_H
#define HBDOCKFLOATINGINSERT_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockFloatingInsert(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int Index,
   HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif