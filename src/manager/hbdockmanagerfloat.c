#include <windows.h>

#include "hbdockmanagerfloat.h"

#include "hbdockmanagerundock.h"
#include "hbdockfloating.h"

BOOL hbDockManagerFloat(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer,
   const RECT * pRect )
{
   HB_DOCK_PANEL * pPanel;

   if( pManager == NULL )
      return FALSE;

   if( pContainer == NULL )
      return FALSE;

   pPanel = pContainer->TabGroup.pPanel;

   if( pPanel == NULL )
      return FALSE;

   if( pPanel->pFloating == NULL )
      return FALSE;

   if( !hbDockManagerUndock(
            pManager,
            pContainer ) )
      return FALSE;

   hbDockFloatingMove(
      pPanel->pFloating,
      pRect );

   hbDockFloatingShow(
      pPanel->pFloating,
      SW_SHOW );

   pPanel->Floating = TRUE;

   return TRUE;
}