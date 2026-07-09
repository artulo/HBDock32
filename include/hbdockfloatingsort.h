#ifndef HBDOCKFLOATINGSORT_H
#define HBDOCKFLOATINGSORT_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ( * HB_DOCK_FLOATING_COMPARE )(
   const HB_DOCK_FLOATING_FRAME * pLeft,
   const HB_DOCK_FLOATING_FRAME * pRight );

void hbDockFloatingSort(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_COMPARE pCompare );

#ifdef __cplusplus
}
#endif

#endif