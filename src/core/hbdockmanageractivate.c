#include <windows.h>

#include "hbdockmanageractivate.h"

#include "hbdockmanagerfindpanel.h"

BOOL hbDockManagerActivatePanel(

        HB_DOCK_MANAGER * pManager,

        LPCTSTR pszName )
{
    HB_DOCK_PANEL * pPanel;

    pPanel =
        hbDockManagerFindPanel(
            pManager,
            pszName );

    if( pPanel == NULL )
        return FALSE;

    SetFocus(
        pPanel->hWnd );

    BringWindowToTop(
        pPanel->hWnd );

    return TRUE;
}