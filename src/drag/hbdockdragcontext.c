#include <windows.h>

#include "hbdockdragcontext.h"

void hbDockDragContextInit(
   HB_DOCK_DRAG_CONTEXT * pContext )
{
   ZeroMemory(
      pContext,
      sizeof( HB_DOCK_DRAG_CONTEXT ) );
}

void hbDockDragContextBegin(
   HB_DOCK_DRAG_CONTEXT * pContext,
   HB_DOCK_PANEL * pPanel,
   POINT pt )
{
   pContext->DragPanel = pPanel;
   pContext->StartPoint = pt;
   pContext->CurrentPoint = pt;
   pContext->Dragging = 1;
   pContext->CurrentSite = HB_DOCKSITE_NONE;
}

void hbDockDragContextMove(
   HB_DOCK_DRAG_CONTEXT * pContext,
   POINT pt )
{
   if( !pContext->Dragging )
      return;

   pContext->CurrentPoint = pt;
}

void hbDockDragContextEnd(
   HB_DOCK_DRAG_CONTEXT * pContext )
{
   pContext->Dragging = 0;
   pContext->DragPanel = NULL;
   pContext->CurrentSite = HB_DOCKSITE_NONE;
}