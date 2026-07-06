#ifndef HBDOCKPANELUSERDATA_H
#define HBDOCKPANELUSERDATA_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockPanelSetUserData(
   HB_DOCK_PANEL * pPanel,
   void * pData );

void * hbDockPanelGetUserData(
   const HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif