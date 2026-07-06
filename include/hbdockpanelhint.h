#ifndef HBDOCKPANELHINT_H
#define HBDOCKPANELHINT_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetHint(
   HB_DOCK_PANEL * pPanel,
   const char * pszHint );

const char * hbDockPanelGetHint(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif