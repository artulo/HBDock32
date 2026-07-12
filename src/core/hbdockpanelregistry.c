#include <stdlib.h>
#include <string.h>

#include "hbdockpanelregistry.h"

BOOL hbDockPanelRegistryInit(
    HB_DOCK_PANEL_REGISTRY * pRegistry )
{
    ZeroMemory(
        pRegistry,
        sizeof(*pRegistry));

    return TRUE;
}

void hbDockPanelRegistryDone(
    HB_DOCK_PANEL_REGISTRY * pRegistry )
{
    HB_DOCK_PANEL * p;
    HB_DOCK_PANEL * n;

    p = pRegistry->First;

    while(p)
    {
        n = p->Next;

        free(p);

        p = n;
    }

    pRegistry->First = NULL;
    pRegistry->Count = 0;
}