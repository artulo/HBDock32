#ifndef HBDOCKPANEL_H
#define HBDOCKPANEL_H

#include <windows.h>

#include "hbdockconfig.h"
#include "hbdockpanelstate.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _HB_DOCK_PANEL HB_DOCK_PANEL;

typedef struct _HB_DOCK_FLOATING HB_DOCK_FLOATING;

typedef struct _HB_DOCK_CONTAINER HB_DOCK_CONTAINER;
 /*
typedef enum _HB_DOCK_PANEL_STATE
{
   HB_PANEL_STATE_NONE = 0,

   HB_PANEL_STATE_DOCKED,

   HB_PANEL_STATE_FLOATING,

   HB_PANEL_STATE_AUTOHIDE,

   HB_PANEL_STATE_HIDDEN

} HB_DOCK_PANEL_STATE;

*/

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



   HB_DOCK_PANEL_STATE State;



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


   HB_DOCK_FLOATING * pFloating;

   HB_DOCK_CONTAINER * pContainer;

   HB_DOCK_PANEL * Next;
};



HB_DOCK_PANEL * hbDockPanelNew(
   void );


void hbDockPanelDelete(
   HB_DOCK_PANEL * pPanel );


void hbDockPanelSetName(
   HB_DOCK_PANEL * pPanel,
   const char * pszName );



#ifdef __cplusplus
}
#endif


#endif /* HBDOCKPANEL_H */