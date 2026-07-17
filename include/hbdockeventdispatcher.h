#ifndef HBDOCKEVENTDISPATCHER_H
#define HBDOCKEVENTDISPATCHER_H

#include <windows.h>
#include "hbdockevent.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_MANAGER HB_DOCK_MANAGER;
typedef struct _HB_DOCK_PANEL   HB_DOCK_PANEL;

typedef void (*HB_DOCK_EVENT_HANDLER_PROC)
(
    HB_DOCK_MANAGER * pManager,
    HB_DOCK_EVENT     Event,
    HB_DOCK_PANEL   * pPanel,
    LPARAM            lParam,
    void            * pUserData
);

typedef struct
{
    HB_DOCK_EVENT_HANDLER_PROC Callback;

    void * UserData;

} HB_DOCK_EVENT_HANDLER;

#define HB_DOCK_MAX_EVENT_HANDLERS 32

typedef struct
{
    HB_DOCK_EVENT_HANDLER Handlers[ HB_DOCK_MAX_EVENT_HANDLERS ];

    UINT Count;

} HB_DOCK_EVENT_DISPATCHER;

BOOL hbDockEventDispatcherInit(
        HB_DOCK_MANAGER * pManager );

void hbDockEventDispatcherDone(
        HB_DOCK_MANAGER * pManager );

BOOL hbDockRegisterEventHandler(
        HB_DOCK_MANAGER * pManager,
        HB_DOCK_EVENT_HANDLER_PROC Proc,
        void * UserData );

BOOL hbDockUnregisterEventHandler(
        HB_DOCK_MANAGER * pManager,
        HB_DOCK_EVENT_HANDLER_PROC Proc );

BOOL hbDockFireEvent(
        HB_DOCK_MANAGER * pManager,
        HB_DOCK_EVENT Event,
        HB_DOCK_PANEL * pPanel,
        LPARAM lParam );

#ifdef __cplusplus
}
#endif

#endif