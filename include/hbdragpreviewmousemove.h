#ifndef HBDRAGPREVIEWMOUSEMOVE_H
#define HBDRAGPREVIEWMOUSEMOVE_H

#include "hbdragpreviewcontroller.h"

#ifdef __cplusplus
extern "C" {
#endif
void hbDragPreviewMouseMove(
    HB_DOCK_PREVIEW_OVERLAY * pPreview,
    POINT pt );
	/*
void hbDragPreviewMouseMove(
      HB_DRAG_PREVIEW_CONTROLLER * pController,
      POINT pt );*/

#ifdef __cplusplus
}
#endif

#endif