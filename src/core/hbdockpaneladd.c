#include <stdlib.h>

#include "hbdockpaneladd.h"

BOOL hbDockPanelAdd(
      HB_DOCK_PANEL_REGISTRY * pRegistry,
      HWND hWnd,
      LPCTSTR pszName,
      LPCTSTR pszCaption )
{
    HB_DOCK_PANEL * p;

    p = (HB_DOCK_PANEL *)
        calloc(1,sizeof(HB_DOCK_PANEL));

    if(p==NULL)
        return FALSE;

    p->hWnd = hWnd;

    lstrcpy(p->Name,pszName);

    lstrcpy(p->Caption,pszCaption);

    p->Next =
        pRegistry->First;

    pRegistry->First = p;

    pRegistry->Count++;

    return TRUE;
}