#include <windows.h>

#include "hbdockguidelayout.h"

#define GUIDE_SIZE 40
#define GUIDE_SPACE 12

void hbDockGuideManagerLayout(
   HB_DOCK_GUIDE_MANAGER * pManager,
   const RECT * pRect )
{
   int cx;
   int cy;

   if( pManager == NULL )
      return;

   cx = ( pRect->left + pRect->right ) / 2;
   cy = ( pRect->top + pRect->bottom ) / 2;

   SetRect(
      &pManager->Guides[0].Rect,
      cx - GUIDE_SIZE * 2,
      cy,
      cx - GUIDE_SIZE,
      cy + GUIDE_SIZE );

   SetRect(
      &pManager->Guides[1].Rect,
      cx + GUIDE_SIZE,
      cy,
      cx + GUIDE_SIZE * 2,
      cy + GUIDE_SIZE );

   SetRect(
      &pManager->Guides[2].Rect,
      cx,
      cy - GUIDE_SIZE * 2,
      cx + GUIDE_SIZE,
      cy - GUIDE_SIZE );

   SetRect(
      &pManager->Guides[3].Rect,
      cx,
      cy + GUIDE_SIZE,
      cx + GUIDE_SIZE,
      cy + GUIDE_SIZE * 2 );

   SetRect(
      &pManager->Guides[4].Rect,
      cx,
      cy,
      cx + GUIDE_SIZE,
      cy + GUIDE_SIZE );
}