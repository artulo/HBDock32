#ifndef HBDOCKMANAGER_H
#define HBDOCKMANAGER_H

#include <windows.h>

#include "hbdocklayouttree.h"
#include "hbdockpreviewoverlay.h"
#include "hbdockguidemanager.h"
#include "hbdockdiamond.h"
#include "hbdockautohideanimationmanager.h"
#include "hbdockscheduler.h"
#include "hbdockpanelregistry.h"
#include "hbdockcommandqueue.h"
#include "hbdocktransaction.h"
#include "hbdockeventdispatcher.h"
#include "hbdockautohidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_MANAGER
{
    HWND hMainWnd;

    HB_DOCK_LAYOUT_TREE LayoutTree;

   HB_DOCK_PANEL_REGISTRY Registry;

    HB_DOCK_EVENT_DISPATCHER Dispatcher;

    HB_DOCK_GUIDE_MANAGER GuideManager;

    HB_DOCK_PREVIEW_OVERLAY Preview;

    HB_DOCK_DIAMOND Diamond;

	HB_DOCK_AUTOHIDE_MANAGER AutoHideManager;

    HB_DOCK_AUTOHIDE_ANIMATION_MANAGER AnimationManager;
	
 	HB_DOCK_COMMAND_QUEUE CommandQueue;
	
 	HB_DOCK_TRANSACTION Transaction;
	
	HB_DOCK_SCHEDULER Scheduler;

    HWND hCapturedWindow;

    BOOL Dragging;

    BOOL UpdatingLayout;

} HB_DOCK_MANAGER;

BOOL hbDockManagerCreate(
      HB_DOCK_MANAGER * pManager,
      HWND hWnd );

void hbDockManagerDestroy(
      HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif