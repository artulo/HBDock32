#ifndef HBDOCKPANEL_H
#define HBDOCKPANEL_H

#include <windows.h>

typedef struct _HB_DOCK_PANEL HB_DOCK_PANEL;

struct _HB_DOCK_PANEL
{
    HWND hWnd;

    char Name[64];

    RECT Rect;

    int DockSide;

    int MinWidth;
    int MinHeight;

    int Visible;

    void * Cargo;

    HB_DOCK_PANEL * Next;
};

HB_DOCK_PANEL * hbDockPanelNew( void );

void hbDockPanelDelete(
    HB_DOCK_PANEL * pPanel );

void hbDockPanelSetName(
    HB_DOCK_PANEL * pPanel,
    const char * pszName );

#endif