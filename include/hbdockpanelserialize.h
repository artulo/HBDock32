#ifndef HBDOCKPANELSERIALIZE_H
#define HBDOCKPANELSERIALIZE_H

#include <stdio.h>

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

int hbDockPanelSave(
   FILE * fp,
   const HB_DOCK_PANEL * pPanel );

int hbDockPanelLoad(
   FILE * fp,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif