#include "hbdockmanagerregister.h"

#include "hbdockpaneladd.h"

BOOL hbDockManagerRegisterPanel(

        HB_DOCK_MANAGER * pManager,

        HWND hWnd,

        LPCTSTR pszName,

        LPCTSTR pszCaption )
{
    return hbDockPanelAdd(

        &pManager->Registry,

        hWnd,

        pszName,

        pszCaption );
}