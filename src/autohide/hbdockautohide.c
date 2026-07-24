#include <windows.h>

#include "hbdockautohide.h"

void hbDockAutoHideInit(
   HB_DOCK_AUTOHIDE * pAutoHide,
   HB_DOCK_PANEL * pPanel )
{
   if( pAutoHide == NULL )
      return;

   ZeroMemory(
      pAutoHide,
      sizeof( HB_DOCK_AUTOHIDE ) );

   pAutoHide->Panel = pPanel;
}

void hbDockAutoHideEnable(
   HB_DOCK_AUTOHIDE * pAutoHide,
   int Enable )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Enabled = Enable;
}

void hbDockAutoHideExpand(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Expanded = 1;

   if( pAutoHide->Panel != NULL )
      pAutoHide->Panel->Rect =
         pAutoHide->VisibleRect;
}

void hbDockAutoHideCollapse(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   pAutoHide->Expanded = 0;

   if( pAutoHide->Panel != NULL )
      pAutoHide->Panel->Rect =
         pAutoHide->HiddenRect;
}