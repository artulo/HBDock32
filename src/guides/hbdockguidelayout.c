#include <windows.h>

#include "hbdockguidelayout.h"


void hbDockGuideManagerLayout(
   HB_DOCK_GUIDE_MANAGER * pManager,
   const RECT * pRect )
{
   RECT rcClient;
   int cx;
   int cy;


   if( pManager == NULL )
      return;


   if( pRect == NULL )
      return;


   rcClient = *pRect;


   cx =
      rcClient.right -
      rcClient.left;


   cy =
      rcClient.bottom -
      rcClient.top;


   /*
    * Guía izquierda
    */
   SetRect(
      &pManager->Left.Rect,
      rcClient.left,
      rcClient.top + cy / 2 - 20,
      rcClient.left + 40,
      rcClient.top + cy / 2 + 20 );

   pManager->Left.Type =
      HB_GUIDE_LEFT;


   /*
    * Guía derecha
    */
   SetRect(
      &pManager->Right.Rect,
      rcClient.right - 40,
      rcClient.top + cy / 2 - 20,
      rcClient.right,
      rcClient.top + cy / 2 + 20 );

   pManager->Right.Type =
      HB_GUIDE_RIGHT;


   /*
    * Guía superior
    */
   SetRect(
      &pManager->Top.Rect,
      rcClient.left + cx / 2 - 20,
      rcClient.top,
      rcClient.left + cx / 2 + 20,
      rcClient.top + 40 );

   pManager->Top.Type =
      HB_GUIDE_TOP;


   /*
    * Guía inferior
    */
   SetRect(
      &pManager->Bottom.Rect,
      rcClient.left + cx / 2 - 20,
      rcClient.bottom - 40,
      rcClient.left + cx / 2 + 20,
      rcClient.bottom );

   pManager->Bottom.Type =
      HB_GUIDE_BOTTOM;


   /*
    * Guía central
    */
   SetRect(
      &pManager->Center.Rect,
      rcClient.left + cx / 2 - 20,
      rcClient.top + cy / 2 - 20,
      rcClient.left + cx / 2 + 20,
      rcClient.top + cy / 2 + 20 );

   pManager->Center.Type =
      HB_GUIDE_CENTER;
}