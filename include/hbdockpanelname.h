#ifndef HBDOCKPANELNAME_H
#define HBDOCKPANELNAME_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetName(
   HB_DOCK_PANEL * pPanel,
   const char * pszName );

const char * hbDockPanelGetName(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif