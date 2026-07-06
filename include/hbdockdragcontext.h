#ifndef HBDOCKDRAGCONTEXT_H
#define HBDOCKDRAGCONTEXT_H

#include <windows.h>

#include "hbdockpanel.h"
#include "hbdockdocksite.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_DRAG_CONTEXT
{
   HB_DOCK_PANEL * DragPanel;

   POINT StartPoint;
   POINT CurrentPoint;

   HB_DOCK_SITE CurrentSite;

   int Dragging;

} HB_DOCK_DRAG_CONTEXT;

void hbDockDragContextInit(
   HB_DOCK_DRAG_CONTEXT * pContext );

void hbDockDragContextBegin(
   HB_DOCK_DRAG_CONTEXT * pContext,
   HB_DOCK_PANEL * pPanel,
   POINT pt );

void hbDockDragContextMove(
   HB_DOCK_DRAG_CONTEXT * pContext,
   POINT pt );

void hbDockDragContextEnd(
   HB_DOCK_DRAG_CONTEXT * pContext );

#ifdef __cplusplus
}
#endif

#endif