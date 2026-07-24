#include <windows.h>

#include "hbdockdragpreview.h"

static void hbDockGuideToPreviewRect(
   HB_DOCK_GUIDE_TYPE Guide,
   const RECT * pClient,
   RECT * pPreview )
{
   *pPreview = *pClient;

   switch( Guide )
   {
      case HB_GUIDE_LEFT:

         pPreview->right =
            pPreview->left +
            ( pClient->right - pClient->left ) / 2;
         break;

      case HB_GUIDE_RIGHT:

         pPreview->left =
            pPreview->left +
            ( pClient->right - pClient->left ) / 2;
         break;

      case HB_GUIDE_TOP:

         pPreview->bottom =
            pPreview->top +
            ( pClient->bottom - pClient->top ) / 2;
         break;

      case HB_GUIDE_BOTTOM:

         pPreview->top =
            pPreview->top +
            ( pClient->bottom - pClient->top ) / 2;
         break;

      case HB_GUIDE_CENTER:

         break;

      default:

         SetRectEmpty(
            pPreview );
         break;
   }
}

void hbDockDragPreviewUpdate(
   HB_DOCK_MANAGER * pManager,
   POINT pt )
{
   RECT rcClient;
   RECT rcPreview;
 
   HB_DOCK_GUIDE_TYPE Guide;

   if( pManager == NULL )
      return;

   Guide =
      hbDockGuideManagerHitTest(
         &pManager->GuideManager,
         pt );

   if( Guide == HB_GUIDE_NONE )
   {
      hbDockPreviewOverlayHide(
         &pManager->Preview );

      return;
   }

   GetClientRect(
      pManager->hMainWnd,
      &rcClient );

   hbDockGuideToPreviewRect(
      Guide,
      &rcClient,
      &rcPreview );

   hbDockPreviewOverlayShow(
      &pManager->Preview,
      &rcPreview );
}

void hbDockDragPreviewHide(
   HB_DOCK_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   hbDockPreviewOverlayHide(
      &pManager->Preview );
}