#include <windows.h>

#include "hbdocktabcontrol.h"

void hbDockTabControlInit(
   HB_DOCK_TAB_CONTROL * pControl,
   HB_DOCK_TAB_GROUP * pGroup )
{
   ZeroMemory(
      pControl,
      sizeof( HB_DOCK_TAB_CONTROL ) );

   pControl->Group = pGroup;
}

void hbDockTabControlLayout(
   HB_DOCK_TAB_CONTROL * pControl,
   const RECT * pRect )
{
   int i;
   int x;

   pControl->Rect = *pRect;

   x = pRect->left;

   for( i = 0;
        i < pControl->Group->Count;
        i++ )
   {
      SetRect(
         &pControl->TabRects[ i ],
         x,
         pRect->top,
         x + 120,
         pRect->top + HBDOCK_TAB_HEIGHT );

      x += 120;
   }
}

void hbDockTabControlDraw(
   HDC hDC,
   HB_DOCK_TAB_CONTROL * pControl )
{
   int i;

   for( i = 0;
        i < pControl->Group->Count;
        i++ )
   {
      Rectangle(
         hDC,
         pControl->TabRects[ i ].left,
         pControl->TabRects[ i ].top,
         pControl->TabRects[ i ].right,
         pControl->TabRects[ i ].bottom );
   }
}

int hbDockTabControlHitTest(
   HB_DOCK_TAB_CONTROL * pControl,
   POINT pt )
{
   int i;

   for( i = 0;
        i < pControl->Group->Count;
        i++ )
   {
      if( PtInRect(
             &pControl->TabRects[ i ],
             pt ) )
         return i;
   }

   return -1;
}