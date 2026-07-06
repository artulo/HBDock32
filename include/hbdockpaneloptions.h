#ifndef HBDOCKPANELOPTIONS_H
#define HBDOCKPANELOPTIONS_H

#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HB_DOCK_OPTION_CLOSEBUTTON   0x00000001UL
#define HB_DOCK_OPTION_PINBUTTON     0x00000002UL
#define HB_DOCK_OPTION_MENUBUTTON    0x00000004UL
#define HB_DOCK_OPTION_FLOATABLE     0x00000008UL
#define HB_DOCK_OPTION_DOCKABLE      0x00000010UL
#define HB_DOCK_OPTION_AUTOHIDE      0x00000020UL
#define HB_DOCK_OPTION_TABSTOP       0x00000040UL
#define HB_DOCK_OPTION_VISIBLE       0x00000080UL

void hbDockPanelSetOptions(
   HB_DOCK_PANEL * pPanel,
   unsigned long ulOptions );

unsigned long hbDockPanelGetOptions(
   const HB_DOCK_PANEL * pPanel );

void hbDockPanelEnableOption(
   HB_DOCK_PANEL * pPanel,
   unsigned long ulOption );

void hbDockPanelDisableOption(
   HB_DOCK_PANEL * pPanel,
   unsigned long ulOption );

int hbDockPanelHasOption(
   const HB_DOCK_PANEL * pPanel,
   unsigned long ulOption );

#ifdef __cplusplus
}
#endif

#endif