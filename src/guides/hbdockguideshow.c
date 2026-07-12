#include <windows.h>

#include "hbdockguideshow.h"

void hbDockGuideShow(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide == NULL )
      return;

   pGuide->Visible = TRUE;

   ShowWindow(
      pGuide->hWnd,
      SW_SHOWNA );
}

void hbDockGuideHide(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide == NULL )
      return;

   pGuide->Visible = FALSE;

   ShowWindow(
      pGuide->hWnd,
      SW_HIDE );
}

BOOL hbDockGuideIsVisible(
   const HB_DOCK_GUIDE * pGuide )
{
   if( pGuide == NULL )
      return FALSE;

   return pGuide->Visible;
}