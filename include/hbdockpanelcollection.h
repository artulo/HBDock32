#ifndef HBDOCKPANELCOLLECTION_H
#define HBDOCKPANELCOLLECTION_H

#include "hbdockarray.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_ARRAY Items;

} HB_DOCK_PANEL_COLLECTION;

void hbDockPanelCollectionInit(
   HB_DOCK_PANEL_COLLECTION * pCollection );

void hbDockPanelCollectionRelease(
   HB_DOCK_PANEL_COLLECTION * pCollection );

int hbDockPanelCollectionAdd(
   HB_DOCK_PANEL_COLLECTION * pCollection,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_PANEL * hbDockPanelCollectionGet(
   HB_DOCK_PANEL_COLLECTION * pCollection,
   int Index );

int hbDockPanelCollectionCount(
   const HB_DOCK_PANEL_COLLECTION * pCollection );

#ifdef __cplusplus
}
#endif

#endif