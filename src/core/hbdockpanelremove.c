#include <stdlib.h>

#include "hbdockpanelremove.h"

BOOL hbDockPanelRemove(
      HB_DOCK_PANEL_REGISTRY * pRegistry,
      HWND hWnd )
{
    HB_DOCK_PANEL * p;
    HB_DOCK_PANEL * prev;

    prev=NULL;

    p=pRegistry->First;

    while(p)
    {
        if(p->hWnd==hWnd)
        {
            if(prev)
                prev->Next=p->Next;
            else
                pRegistry->First=p->Next;

            free(p);

            pRegistry->Count--;

            return TRUE;
        }

        prev=p;

        p=p->Next;
    }

    return FALSE;
}