#ifndef HBDOCKDRAGPREVIEW_H
#define HBDOCKDRAGPREVIEW_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockguidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockDragPreviewUpdate(
   HB_DOCK_MANAGER * pManager,
   POINT pt );

void hbDockDragPreviewHide(
   HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif