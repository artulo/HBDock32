#include <windows.h>

#include "hbdockfloatingarrange.h"

static void hbDockFloatingForEach(
   HB_DOCK_FLOATING_MANAGER * pManager,
   int nCmd )
{
   int i;

   if( pManager == NULL )
      return;

   for( i = 0; i < pManager->Frames.Count; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame != NULL &&
          pFrame->hWnd != NULL )
      {
         ShowWindow(
            pFrame->hWnd,
            nCmd );
      }
   }
}

void hbDockFloatingArrangeIcons(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   int i;

   if( pManager == NULL )
      return;

   for( i = 0; i < pManager->Frames.Count; ++i )
   {
      HB_DOCK_FLOATING_FRAME * pFrame;

      pFrame =
         ( HB_DOCK_FLOATING_FRAME * )
         hbDockArrayGet(
            &pManager->Frames,
            i );

      if( pFrame != NULL &&
          pFrame->hWnd != NULL )
      {
         OpenIcon(
            pFrame->hWnd );
      }
   }
}

void hbDockFloatingRestoreAll(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   hbDockFloatingForEach(
      pManager,
      SW_RESTORE );
}

void hbDockFloatingMinimizeAll(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   hbDockFloatingForEach(
      pManager,
      SW_MINIMIZE );
}

void hbDockFloatingMaximizeAll(
   HB_DOCK_FLOATING_MANAGER * pManager )
{
   hbDockFloatingForEach(
      pManager,
      SW_MAXIMIZE );
}