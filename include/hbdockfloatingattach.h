#ifndef HBDOCKFLOATINGATTACH_H
#define HBDOCKFLOATINGATTACH_H

#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockFloatingAttachPanel(
   HB_DOCK_FLOATING_FRAME * pFrame,
   HB_DOCK_PANEL * pPanel );

HB_DOCK_PANEL * hbDockFloatingDetachPanel(
   HB_DOCK_FLOATING_FRAME * pFrame );

HB_DOCK_PANEL * hbDockFloatingGetPanel(
   const HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif