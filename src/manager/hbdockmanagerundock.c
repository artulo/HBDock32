#include <windows.h>

#include "hbdockmanagerundock.h"

#include "hbdocklayoutremovepanel.h"
#include "hbdocklayoutremoveempty.h"
#include "hbdocklayoutoptimizer.h"
#include "hbdocklayoutrecalc.h"
#include "hbdockmanagerrefreshlayout.h"

BOOL hbDockManagerUndock(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer )
{
   if( pManager == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   if( !hbDockLayoutRemovePanel(
            &pManager->LayoutTree,
            pContainer ) )
      return FALSE;

   return hbDockManagerRefreshLayout(
      pManager );
}