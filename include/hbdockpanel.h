#ifndef HBDOCKPANEL_H
#define HBDOCKPANEL_H

#include <windows.h>

#include "hbdockconfig.h"

typedef struct _HB_DOCK_PANEL HB_DOCK_PANEL;

struct _HB_DOCK_PANEL
{
    HWND hWnd;
    HWND hParent;
    HWND hToolTip;

    char Name[64];
    char Caption[HBDOCK_MAX_CAPTION];
    char Hint[HBDOCK_MAX_CAPTION];

    RECT Rect;
    RECT FloatRect;
    RECT Margin;
    RECT Padding;

    int DockSide;
    int DockSite;

    int MinWidth;
    int MinHeight;

    SIZE MinSize;
    SIZE MaxSize;
    SIZE DockSize;

    int PreferredSize;

    int Visible;
    int Enabled;
    int Active;
    int Floating;
    int Modified;
    int Border;
    int UpdateCount;

    int Align;
    int State;

    unsigned int Id;
    long Tag;

    unsigned long Flags;
    unsigned long Options;

    DWORD Style;
    DWORD ExStyle;

    COLORREF BkColor;
    COLORREF TextColor;

    HFONT hFont;
    HICON hIcon;
    HCURSOR hCursor;

    void * UserData;
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