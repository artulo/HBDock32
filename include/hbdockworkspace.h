#ifndef HBDOCKWORKSPACE_H
#define HBDOCKWORKSPACE_H

#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockWorkspaceSave(
      HB_DOCK_MANAGER * pManager,
      LPCTSTR pszFile );

BOOL hbDockWorkspaceLoad(
      HB_DOCK_MANAGER * pManager,
      LPCTSTR pszFile );

#ifdef __cplusplus
}
#endif

#endif