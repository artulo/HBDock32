#include <windows.h>

#include "hbdocksplitnode.h"
#include "hbdockconfig.h"

void hbDockSplitNodeInit(
   HB_DOCK_SPLIT_NODE * pSplit,
   HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pSplit == NULL )
      return;

   ZeroMemory(
      pSplit,
      sizeof( HB_DOCK_SPLIT_NODE ) );

   pSplit->Node = pNode;

   pSplit->Tracking = FALSE;

   pSplit->MinFirst  = 80;
   pSplit->MinSecond = 80;

   hbDockSplitNodeUpdate(
      pSplit );
}

void hbDockSplitNodeUpdate(
   HB_DOCK_SPLIT_NODE * pSplit )
{
   RECT rc;
   LONG Size;
   LONG Pos;

   if( pSplit == NULL )
      return;

   if( pSplit->Node == NULL )
      return;

   rc = pSplit->Node->Rect;

   if( pSplit->Node->Type == HB_LAYOUT_HORIZONTAL )
   {
      Size = rc.right - rc.left;

      Pos = ( LONG ) ( ( double ) Size *
                       pSplit->Node->Ratio );

      rc.left  += Pos;
      rc.right  = rc.left + HBDOCK_SPLITTER_WIDTH;
   }
   else
   {
      Size = rc.bottom - rc.top;

      Pos = ( LONG ) ( ( double ) Size *
                       pSplit->Node->Ratio );

      rc.top    += Pos;
      rc.bottom  = rc.top + HBDOCK_SPLITTER_WIDTH;
   }

   pSplit->SplitterRect = rc;
}

int hbDockSplitNodeHitTest(
   const HB_DOCK_SPLIT_NODE * pSplit,
   POINT pt )
{
   if( pSplit == NULL )
      return FALSE;

   return PtInRect(
      &pSplit->SplitterRect,
      pt );
}

void hbDockSplitNodeMove(
   HB_DOCK_SPLIT_NODE * pSplit,
   float BaseRatio,
   int Delta )
{
   LONG Size;
   double Ratio;

   if( pSplit == NULL )
      return;

   if( pSplit->Node == NULL )
      return;

   if( pSplit->Node->Type == HB_LAYOUT_HORIZONTAL )
      Size = pSplit->Node->Rect.right -
             pSplit->Node->Rect.left;
   else
      Size = pSplit->Node->Rect.bottom -
             pSplit->Node->Rect.top;

   if( Size <= 0 )
      return;

   /*
    * Etapa 50: cuantizar el delta a multiplos de
    * HBDOCK_SPLITTER_STEP -- con el valor default (1) esto no cambia
    * nada (todo entero ya es multiplo de 1).
    */
#if HBDOCK_SPLITTER_STEP > 1
   Delta =
      ( Delta / HBDOCK_SPLITTER_STEP ) *
      HBDOCK_SPLITTER_STEP;
#endif

   /*
    * Etapa 50 (fix): usar el ratio BASE recibido (capturado por el
    * tracker al EMPEZAR el arrastre -- ver hbDockSplitterTrackerBegin
    * en hbdocksplittertracker.c), no pSplit->Node->Ratio (el valor
    * YA MODIFICADO por la llamada anterior). El tracker manda Delta
    * como el desplazamiento ACUMULADO desde el inicio del drag, no
    * incremental desde el ultimo tick -- sumarlo sobre el ratio ya
    * mutado componia el desplazamiento sobre si mismo en cada
    * WM_MOUSEMOVE, haciendo que el splitter se moviera muchisimo mas
    * de lo que el mouse realmente se movio.
    */
   Ratio =
      ( double ) BaseRatio +
      ( ( double ) Delta / ( double ) Size );

   if( Ratio < 0.10 )
      Ratio = 0.10;

   if( Ratio > 0.90 )
      Ratio = 0.90;

   pSplit->Node->Ratio = ( float ) Ratio;

   hbDockSplitNodeUpdate(
      pSplit );
}