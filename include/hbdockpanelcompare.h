#ifndef HBDOCKPANELCOMPARE_H
#define HBDOCKPANELCOMPARE_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockPanelCompareId(
   const HB_DOCK_PANEL * p1,
   const HB_DOCK_PANEL * p2 );

int hbDockPanelCompareName(
   const HB_DOCK_PANEL * p1,
   const HB_DOCK_PANEL * p2 );

#ifdef __cplusplus
}
#endif

#endif