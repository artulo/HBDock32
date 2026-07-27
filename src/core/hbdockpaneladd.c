#include <stdlib.h>
#include <windows.h>

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

    /* Nota de estabilizacion (Etapa 3): lstrcpy() no acota longitud.
     * p->Name y p->Caption son buffers fijos (Name[64], Caption[128]
     * en hbdockpanel.h) y pszName/pszCaption vienen del lado Harbour,
     * con longitud arbitraria -- un nombre o caption mas largo que el
     * buffer corrompia memoria del heap. Se usa lstrcpyn con el
     * tamano real del buffer para truncar en vez de desbordar. */
    lstrcpyn( p->Name, pszName, sizeof( p->Name ) );

    lstrcpyn( p->Caption, pszCaption, sizeof( p->Caption ) );

    p->Next =
        pRegistry->First;

    pRegistry->First = p;

    pRegistry->Count++;

    return TRUE;
}