#ifndef HBDOCKEVENT_H
#define HBDOCKEVENT_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCK_EVENT_NONE = 0,
   HB_DOCK_EVENT_DOCK,
   HB_DOCK_EVENT_UNDOCK,
   HB_DOCK_EVENT_SHOW,
   HB_DOCK_EVENT_HIDE,
   HB_DOCK_EVENT_ACTIVATE,
   HB_DOCK_EVENT_CLOSE,
   HB_DOCK_EVENT_BEGIN_DRAG,
   HB_DOCK_EVENT_DRAGGING,
   HB_DOCK_EVENT_END_DRAG,
   HB_DOCK_EVENT_LAYOUT

} HB_DOCK_EVENT;

typedef void ( *HB_DOCK_EVENT_PROC )
(
   HWND,
   HB_DOCK_EVENT,
   void *
);

void hbDockSetEventProc(
   HB_DOCK_EVENT_PROC pProc );

HB_DOCK_EVENT_PROC hbDockGetEventProc( void );

void hbDockSendEvent(
   HWND hWnd,
   HB_DOCK_EVENT Event,
   void * pData );

#ifdef __cplusplus
}
#endif

#endif