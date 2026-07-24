#include <windows.h>

#include "hbdockautohideshowstate.h"

void hbDockAutoHideMinimize(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   ShowWindow(
      pAutoHide->Panel->hWnd,
      SW_MINIMIZE );
}

void hbDockAutoHideMaximize(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   ShowWindow(
      pAutoHide->Panel->hWnd,
      SW_MAXIMIZE );
}

void hbDockAutoHideRestore(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( pAutoHide->Panel == NULL )
      return;

   if( pAutoHide->Panel->hWnd == NULL )
      return;

   ShowWindow(
      pAutoHide->Panel->hWnd,
      SW_RESTORE );
}