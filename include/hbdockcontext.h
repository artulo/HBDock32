#ifndef HBDOCKCONTEXT_H
#define HBDOCKCONTEXT_H

#include "hbdockmanager.h"
#include "hbdockpanelregistry.h"
#include "hbdocklayouttree.h"
#include "hbdockcommandqueue.h"
#include "hbdocktransaction.h"
#include "hbdockeventdispatcher.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    HB_DOCK_MANAGER        * Manager;

    HB_DOCK_LAYOUT_TREE    * Layout;

    HB_DOCK_PANEL_REGISTRY * Registry;

    HB_DOCK_COMMAND_QUEUE  * Queue;

    HB_DOCK_TRANSACTION    * Transaction;

    void * Scheduler;

    void * ResourceManager;

} HB_DOCK_CONTEXT;

BOOL hbDockContextInitialize(
        HB_DOCK_CONTEXT * pContext,
        HB_DOCK_MANAGER * pManager );

void hbDockContextDone(
        HB_DOCK_CONTEXT * pContext );

#ifdef __cplusplus
}
#endif

#endif