#ifndef HBDOCKPANELCLONE_H
#define HBDOCKPANELCLONE_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_PANEL * hbDockPanelClone(
   const HB_DOCK_PANEL * pPanel );

void hbDockPanelCopy(
   HB_DOCK_PANEL * pDest,
   const HB_DOCK_PANEL * pSource );

#ifdef __cplusplus
}
#endif

#endif