#include "hbdragpreviewcalc.h"

void hbDragPreviewCalcRect(
   const RECT * pHost,
   HB_DOCK_DIAMOND_BUTTON Button,
   RECT * pPreview )
{
   *pPreview = *pHost;

   switch( Button )
   {
      case HB_DIAMOND_LEFT:

         pPreview->right =
            pPreview->left +
            ( pPreview->right -
              pPreview->left ) / 3;

         break;

      case HB_DIAMOND_RIGHT:

         pPreview->left =
            pPreview->right -
            ( pPreview->right -
              pPreview->left ) / 3;

         break;

      case HB_DIAMOND_TOP:

         pPreview->bottom =
            pPreview->top +
            ( pPreview->bottom -
              pPreview->top ) / 3;

         break;

      case HB_DIAMOND_BOTTOM:

         pPreview->top =
            pPreview->bottom -
            ( pPreview->bottom -
              pPreview->top ) / 3;

         break;

      case HB_DIAMOND_CENTER:

         break;

      default:

         SetRectEmpty(
            pPreview );
   }
}