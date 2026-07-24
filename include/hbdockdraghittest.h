#ifndef HBDOCKDRAGHITTEST_H
#define HBDOCKDRAGHITTEST_H

#include "hbdockguidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _HB_DOCK_DRAG_CONTROLLER;

HB_DOCK_GUIDE_TYPE hbDockDragHitTest(
   struct _HB_DOCK_DRAG_CONTROLLER * pController );

#ifdef __cplusplus
}
#endif

#endif