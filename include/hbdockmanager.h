#ifndef HBDOCKMANAGER_H
#define HBDOCKMANAGER_H

#include <windows.h>

#include "hbdockpanel.h"

typedef struct _HB_DOCK_MANAGER
{
    HWND hParent;

    RECT ClientRect;

    HB_DOCK_PANEL * FirstPanel;
    HB_DOCK_PANEL * LastPanel;

    int PanelCount;

} HB_DOCK_MANAGER;

HB_DOCK_MANAGER * hbDockManagerNew(
    HWND hWnd );

void hbDockManagerDelete(
    HB_DOCK_MANAGER * pManager );

void hbDockManagerAddPanel(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel );

HB_DOCK_PANEL * hbDockManagerFindPanel(
    HB_DOCK_MANAGER * pManager,
    const char * pszName );

void hbDockManagerRemovePanel(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_PANEL * pPanel );

void hbDockManagerLayout(
    HB_DOCK_MANAGER * pManager );

#endif