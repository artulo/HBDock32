#ifndef HBDOCKPANELALIGN_H
#define HBDOCKPANELALIGN_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCK_ALIGN_NONE = 0,
   HB_DOCK_ALIGN_LEFT,
   HB_DOCK_ALIGN_RIGHT,
   HB_DOCK_ALIGN_TOP,
   HB_DOCK_ALIGN_BOTTOM,
   HB_DOCK_ALIGN_CLIENT

} HB_DOCK_ALIGN;

void hbDockPanelSetAlign(
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_ALIGN Align );

HB_DOCK_ALIGN hbDockPanelGetAlign(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif