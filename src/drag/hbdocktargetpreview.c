#include "hbdocktargetpreview.h"

void hbDockTargetBuildPreview(
      HB_DOCK_TARGET_INFO * pInfo )
{
   RECT * rc = &pInfo->PreviewRect;

   switch( pInfo->Target )
   {
      case HB_DOCK_TARGET_LEFT:

         rc->right =
            rc->left +
            ( rc->right -
              rc->left ) / 2;
         break;

      case HB_DOCK_TARGET_RIGHT:

         rc->left =
            rc->left +
            ( rc->right -
              rc->left ) / 2;
         break;

      case HB_DOCK_TARGET_TOP:

         rc->bottom =
            rc->top +
            ( rc->bottom -
              rc->top ) / 2;
         break;

      case HB_DOCK_TARGET_BOTTOM:

         rc->top =
            rc->top +
            ( rc->bottom -
              rc->top ) / 2;
         break;

      default:
         break;
   }
}