#ifndef HBDOCKPANELTEXT_H
#define HBDOCKPANELTEXT_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetCaption(
   HB_DOCK_PANEL * pPanel,
   const char * pszText );

const char * hbDockPanelGetCaption(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif