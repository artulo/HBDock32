#ifndef HBDOCKPANELREGISTRY_H
#define HBDOCKPANELREGISTRY_H

#include <windows.h>
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_MAX_NAME      64
#define HB_DOCK_MAX_CAPTION  128

typedef struct
{
    HB_DOCK_PANEL * First;
    UINT Count;

} HB_DOCK_PANEL_REGISTRY;

BOOL hbDockPanelRegistryInit(
    HB_DOCK_PANEL_REGISTRY * pRegistry );

void hbDockPanelRegistryDone(
    HB_DOCK_PANEL_REGISTRY * pRegistry );

#ifdef __cplusplus
}
#endif

#endif