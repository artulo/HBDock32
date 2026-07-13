#include "hbdockkernel.h"

#include "hbdockcommandqueue.h"
#include "hbdockeventdispatcher.h"
#include "hbdocklayoutsync.h"
#include "hbdockengineprocess.h"

BOOL hbDockKernelInitialize(
        HB_DOCK_MANAGER * pManager )
{
    hbDockCommandQueueInit(
        &pManager->CommandQueue );

    hbDockEventDispatcherInit(
        pManager );

    return TRUE;
}

void hbDockKernelShutdown(
        HB_DOCK_MANAGER * pManager )
{
    hbDockEventDispatcherDone(
        pManager );
}

BOOL hbDockKernelProcess(
        HB_DOCK_MANAGER * pManager )
{
    if( pManager == NULL )
        return FALSE;

    hbDockEngineProcessQueue(
        pManager );

    hbDockLayoutSynchronize(
        pManager );

    return TRUE;
}

