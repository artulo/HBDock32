#ifndef HBDOCKAUTOHIDESLIDING_H
#define HBDOCKAUTOHIDESLIDING_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockAutoHideBeginSlide(
   HB_DOCK_AUTOHIDE * pAutoHide );

void hbDockAutoHideEndSlide(
   HB_DOCK_AUTOHIDE * pAutoHide );

int hbDockAutoHideIsSliding(
   const HB_DOCK_AUTOHIDE * pAutoHide );

#ifdef __cplusplus
}
#endif

#endif