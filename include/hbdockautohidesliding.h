#ifndef HBDOCKAUTOHIDESLIDING_H
#define HBDOCKAUTOHIDESLIDING_H

#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane );

void hbDockAutoHideEndSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane );

int hbDockAutoHideIsSliding(
   const HB_DOCK_AUTOHIDE_PANE * pPane );

#ifdef __cplusplus
}
#endif

#endif