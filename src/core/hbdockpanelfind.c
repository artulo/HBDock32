#include <string.h>

#include "hbdockpanelfind.h"

HB_DOCK_PANEL *
hbDockPanelFindName(
      HB_DOCK_PANEL_REGISTRY * pRegistry,
      LPCTSTR pszName )
{
    HB_DOCK_PANEL * p;

    p = pRegistry->First;

    while(p)
    {
        if(lstrcmpi(
            p->Name,
            pszName)==0)
            return p;

        p = p->Next;
    }

    return NULL;
}

HB_DOCK_PANEL *
hbDockPanelFindHWND(
      HB_DOCK_PANEL_REGISTRY * pRegistry,
      HWND hWnd )
{
    HB_DOCK_PANEL * p;

    p = pRegistry->First;

    while(p)
    {
        if(p->hWnd==hWnd)
            return p;

        p=p->Next;
    }

    return NULL;
}