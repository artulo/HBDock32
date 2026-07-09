#ifndef HBDOCKFLOATINGCOMPARE_H
#define HBDOCKFLOATINGCOMPARE_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockFloatingCompareHandle(
   const HB_DOCK_FLOATING_FRAME * pLeft,
   const HB_DOCK_FLOATING_FRAME * pRight );

int hbDockFloatingComparePanelId(
   const HB_DOCK_FLOATING_FRAME * pLeft,
   const HB_DOCK_FLOATING_FRAME * pRight );

#ifdef __cplusplus
}
#endif

#endif