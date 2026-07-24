#ifndef HBDOCKPANELSTATE_H
#define HBDOCKPANELSTATE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum _HB_DOCK_PANEL_STATE
{
   HB_PANEL_STATE_NONE = 0,

   HB_PANEL_STATE_DOCKED,

   HB_PANEL_STATE_FLOATING,

   HB_PANEL_STATE_AUTOHIDE,

   HB_PANEL_STATE_HIDDEN

} HB_DOCK_PANEL_STATE;


typedef struct _HB_DOCK_PANEL HB_DOCK_PANEL;


void hbDockPanelSetState(
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_PANEL_STATE State );


HB_DOCK_PANEL_STATE hbDockPanelGetState(
   const HB_DOCK_PANEL * pPanel );


#ifdef __cplusplus
}
#endif

#endif