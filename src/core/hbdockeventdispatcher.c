#include <stdlib.h>
#include <string.h>

#include "hbdockeventdispatcher.h"

#define HB_MAX_EVENT_HANDLERS 64

typedef struct
{
    HB_DOCK_EVENT_HANDLER Handlers[
        HB_MAX_EVENT_HANDLERS ];

    UINT Count;

} HB_DOCK_EVENT_DISPATCHER;

BOOL hbDockEventDispatcherInit(
        HB_DOCK_MANAGER * pManager )
{
    ZeroMemory(

        &pManager->Dispatcher,

        sizeof(
            pManager->Dispatcher ) );

    return TRUE;
}

BOOL hbDockRegisterEventHandler(

        HB_DOCK_MANAGER * pManager,

        HB_DOCK_EVENT_PROC Proc,

        void * UserData )
{
    HB_DOCK_EVENT_DISPATCHER * p;

    p = &pManager->Dispatcher;

    if( p->Count >= HB_MAX_EVENT_HANDLERS )
        return FALSE;

    p->Handlers[
        p->Count ].Callback = Proc;

    p->Handlers[
        p->Count ].UserData = UserData;

    p->Count++;

    return TRUE;
}

BOOL hbDockFireEvent(

        HB_DOCK_MANAGER * pManager,

        HB_DOCK_EVENT Event,

        HB_DOCK_PANEL * pPanel,

        LPARAM lParam )
{
    UINT i;

    HB_DOCK_EVENT_DISPATCHER * p;

    p = &pManager->Dispatcher;

    for( i=0;
         i<p->Count;
         i++ )
    {
        p->Handlers[i].Callback(

            pManager,

            Event,

            pPanel,

            lParam,

            p->Handlers[i].UserData );
    }

    return TRUE;
}

