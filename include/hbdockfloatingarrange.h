#ifndef HBDOCKFLOATINGARRANGE_H
#define HBDOCKFLOATINGARRANGE_H

#include "hbdockfloatingmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingArrangeIcons(
   HB_DOCK_FLOATING_MANAGER * pManager );

void hbDockFloatingRestoreAll(
   HB_DOCK_FLOATING_MANAGER * pManager );

void hbDockFloatingMinimizeAll(
   HB_DOCK_FLOATING_MANAGER * pManager );

void hbDockFloatingMaximizeAll(
   HB_DOCK_FLOATING_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif