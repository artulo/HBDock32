#ifndef HBDOCKMANAGER_H
#define HBDOCKMANAGER_H

#include <windows.h>

#include "hbdockpanel.h"
#include "hbdocklayoutengine.h"
#include "hbdockfocus.h"
#include "hbdockdragtracker.h"
#include "hbdockarray.h"

typedef struct _HB_DOCK_MANAGER
{
    HWND hParent;
    HWND hWnd;
    HINSTANCE hInstance;

    RECT ClientRect;

    HB_DOCK_PANEL * FirstPanel;
    HB_DOCK_PANEL * LastPanel;

    int PanelCount;

    HB_DOCK_LAYOUT_ENGINE LayoutEngine;

    HB_DOCK_FOCUS Focus;

    HB_DOCK_DRAG_TRACKER DragTracker;

    /* Elementos HB_DOCK_FLOATING *, uno por panel flotante activo */
    HB_DOCK_ARRAY FloatWindows;

    /* Elementos HB_DOCK_AUTOHIDE *, uno por panel replegado */
    HB_DOCK_ARRAY AutoHidePanels;

} HB_DOCK_MANAGER;

HB_DOCK_MANAGER * hbDockManagerNew(
    HWND hWnd );

void hbDockManagerDelete(
    HB_DOCK_MANAGER * pManager );

void hbDockManagerSetInstance(
    HB_DOCK_MANAGER * pManager,
    HINSTANCE hInstance );

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