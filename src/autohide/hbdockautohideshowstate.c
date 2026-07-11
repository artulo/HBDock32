#include <windows.h>

#include "hbdockautohideshowstate.h"

void hbDockAutoHideMinimize(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   ShowWindow(
      pPane->hWnd,
      SW_MINIMIZE );
}

void hbDockAutoHideMaximize(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   ShowWindow(
      pPane->hWnd,
      SW_MAXIMIZE );
}

void hbDockAutoHideRestore(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   ShowWindow(
      pPane->hWnd,
      SW_RESTORE );
}