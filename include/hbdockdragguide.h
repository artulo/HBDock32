#ifndef HBDOCKDRAGGUIDE_H
#define HBDOCKDRAGGUIDE_H

#include <windows.h>

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockDragGuideShow(
   HB_DOCK_MANAGER * pManager );

void hbDockDragGuideHide(
   HB_DOCK_MANAGER * pManager );

void hbDockDragGuideMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif