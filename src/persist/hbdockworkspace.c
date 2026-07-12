#include "hbdockworkspace.h"

#include "hbdockpersist.h"

BOOL hbDockWorkspaceSave(
      HB_DOCK_MANAGER * pManager,
      LPCTSTR pszFile )
{
    return hbDockSaveLayout(
        &pManager->LayoutTree,
        pszFile,
        HB_DOCK_FORMAT_XML);
}

BOOL hbDockWorkspaceLoad(
      HB_DOCK_MANAGER * pManager,
      LPCTSTR pszFile )
{
    return hbDockLoadLayout(
        &pManager->LayoutTree,
        pszFile);
}