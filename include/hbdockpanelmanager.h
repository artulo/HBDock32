#ifndef HBDOCKPANELMANAGER_H
#define HBDOCKPANELMANAGER_H

#include "hbdockarray.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_ARRAY Panels;

} HB_DOCK_PANEL_MANAGER;

void hbDockPanelManagerInit(
   HB_DOCK_PANEL_MANAGER * pManager );

void hbDockPanelManagerDestroy(
   HB_DOCK_PANEL_MANAGER * pManager );

int hbDockPanelManagerAdd(
   HB_DOCK_PANEL_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

int hbDockPanelManagerRemove(
   HB_DOCK_PANEL_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_PANEL * hbDockPanelManagerGet(
   HB_DOCK_PANEL_MANAGER * pManager,
   int Index );

#ifdef __cplusplus
}
#endif

#endif