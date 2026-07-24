#include <windows.h>

#include "hbdockdragguide.h"
#include "hbdockguidemanager.h"

void hbDockDragGuideShow(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   hbDockGuideManagerShow(
      &pManager->GuideManager );
}

void hbDockDragGuideHide(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   hbDockGuideManagerHide(
      &pManager->GuideManager );
}

void hbDockDragGuideMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return;

   hbDockGuideManagerMove(
      &pManager->GuideManager,
      pt );
}