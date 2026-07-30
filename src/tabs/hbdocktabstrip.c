#include <windows.h>

#include "hbdocktabstrip.h"

void hbDockTabStripSegmentRect(
   const RECT * pCaptionRect,
   UINT Count,
   UINT Index,
   RECT * pOut )
{
   int nAvailable;
   int nIdealTotal;
   int nSegWidth;
   int nLeft;

   if( pCaptionRect == NULL || pOut == NULL || Count == 0 )
      return;

   nAvailable =
      pCaptionRect->right -
      pCaptionRect->left;

   nIdealTotal =
      ( int ) Count *
      HBDOCK_TAB_SEGMENT_WIDTH;

   /*
    * Si todos los tabs entran holgado con su ancho ideal, se usa
    * ese -- si no, se angostan proporcionalmente para que Count de
    * ellos entren exactos en el ancho disponible (sin scroll ni
    * overflow).
    */
   if( nIdealTotal > nAvailable )
      nSegWidth = nAvailable / ( int ) Count;
   else
      nSegWidth = HBDOCK_TAB_SEGMENT_WIDTH;

   if( nSegWidth < 1 )
      nSegWidth = 1;

   nLeft =
      pCaptionRect->left +
      ( int ) Index * nSegWidth;

   pOut->top    = pCaptionRect->top;
   pOut->bottom = pCaptionRect->bottom;
   pOut->left   = nLeft;

   if( Index + 1 == Count && nSegWidth == HBDOCK_TAB_SEGMENT_WIDTH )
   {
      /*
       * Ultimo tab, con espacio de sobra (no se angostaron) -- se
       * queda con su ancho ideal nada mas, sin estirarse a ocupar
       * el resto del caption (mas claro visualmente donde termina
       * la tira de pestañas).
       */
      pOut->right = nLeft + nSegWidth;
   }
   else if( Index + 1 == Count )
   {
      /* Angostados (no entraban holgado) -- el ultimo llega exacto
       * al borde derecho, para no perder pixeles por redondeo. */
      pOut->right = pCaptionRect->right;
   }
   else
   {
      pOut->right = nLeft + nSegWidth;
   }
}

static void hbDockTabStripCloseRect(
   const RECT * pSegRect,
   RECT * pOut )
{
   int nCenterY;

   nCenterY =
      pSegRect->top +
      ( ( pSegRect->bottom - pSegRect->top ) -
        HBDOCK_TAB_CLOSE_SIZE ) / 2;

   SetRect(
      pOut,
      pSegRect->right - HBDOCK_TAB_CLOSE_SIZE - 6,
      nCenterY,
      pSegRect->right - 6,
      nCenterY + HBDOCK_TAB_CLOSE_SIZE );
}

int hbDockTabStripHitTest(
   const HB_DOCK_TAB_GROUP * pGroup,
   const RECT * pCaptionRect,
   POINT pt,
   BOOL * pbOnClose )
{
   UINT i;
   RECT rcSeg;
   RECT rcClose;

   if( pbOnClose != NULL )
      *pbOnClose = FALSE;

   if( pGroup == NULL || pCaptionRect == NULL )
      return -1;

   if( pGroup->Count == 0 )
      return -1;

   for( i = 0; i < pGroup->Count; i++ )
   {
      hbDockTabStripSegmentRect(
         pCaptionRect,
         pGroup->Count,
         i,
         &rcSeg );

      if( PtInRect( &rcSeg, pt ) )
      {
         hbDockTabStripCloseRect(
            &rcSeg,
            &rcClose );

         if( pbOnClose != NULL &&
             PtInRect( &rcClose, pt ) )
            *pbOnClose = TRUE;

         return ( int ) i;
      }
   }

   return -1;
}

void hbDockTabStripDraw(
   HDC hDC,
   const HB_DOCK_TAB_GROUP * pGroup,
   const RECT * pCaptionRect )
{
   UINT i;
   RECT rcSeg;
   RECT rcClose;
   RECT rcText;
   HBRUSH hBrush;
   HPEN hPen;
   HPEN hOldPen;
   COLORREF OldTextColor;
   int OldBkMode;

   if( hDC == NULL || pGroup == NULL || pCaptionRect == NULL )
      return;

   if( pGroup->Count == 0 )
      return;

   SetBkMode(
      hDC,
      TRANSPARENT );

   for( i = 0; i < pGroup->Count; i++ )
   {
      hbDockTabStripSegmentRect(
         pCaptionRect,
         pGroup->Count,
         i,
         &rcSeg );

      /* Fondo del segmento: activo en azul, inactivos en gris
       * oscuro -- mismo criterio de color que el caption simple de
       * siempre (hbDockCaptionDraw), para consistencia visual. */
      hBrush =
         CreateSolidBrush(
            i == pGroup->ActiveIndex ?
               RGB( 0, 120, 215 ) :
               RGB( 90, 90, 90 ) );

      FillRect(
         hDC,
         &rcSeg,
         hBrush );

      DeleteObject(
         hBrush );

      /* Separador vertical entre tabs (no antes del primero). */
      if( i > 0 )
      {
         hPen =
            CreatePen(
               PS_SOLID,
               1,
               RGB( 255, 255, 255 ) );

         hOldPen =
            ( HPEN ) SelectObject(
               hDC,
               hPen );

         MoveToEx(
            hDC,
            rcSeg.left,
            rcSeg.top,
            NULL );

         LineTo(
            hDC,
            rcSeg.left,
            rcSeg.bottom );

         SelectObject(
            hDC,
            hOldPen );

         DeleteObject(
            hPen );
      }

      hbDockTabStripCloseRect(
         &rcSeg,
         &rcClose );

      /* Texto del tab. */
      rcText = rcSeg;
      rcText.left += 6;
      rcText.right = rcClose.left - 4;

      if( rcText.right < rcText.left )
         rcText.right = rcText.left;

      if( pGroup->Tabs[ i ].Caption[ 0 ] != '\0' )
      {
         OldTextColor =
            SetTextColor(
               hDC,
               RGB( 255, 255, 255 ) );

         OldBkMode =
            SetBkMode(
               hDC,
               TRANSPARENT );

         DrawText(
            hDC,
            pGroup->Tabs[ i ].Caption,
            -1,
            &rcText,
            DT_LEFT |
            DT_VCENTER |
            DT_SINGLELINE |
            DT_END_ELLIPSIS );

         SetBkMode(
            hDC,
            OldBkMode );

         SetTextColor(
            hDC,
            OldTextColor );
      }

      /* Boton de cerrar ("x") -- en TODOS los tabs, no solo el
       * activo, para poder cerrar cualquiera sin tener que
       * activarlo primero. */
      hPen =
         CreatePen(
            PS_SOLID,
            1,
            RGB( 255, 255, 255 ) );

      hOldPen =
         ( HPEN ) SelectObject(
            hDC,
            hPen );

      MoveToEx(
         hDC,
         rcClose.left + 3,
         rcClose.top + 3,
         NULL );

      LineTo(
         hDC,
         rcClose.right - 3,
         rcClose.bottom - 3 );

      MoveToEx(
         hDC,
         rcClose.right - 3,
         rcClose.top + 3,
         NULL );

      LineTo(
         hDC,
         rcClose.left + 3,
         rcClose.bottom - 3 );

      SelectObject(
         hDC,
         hOldPen );

      DeleteObject(
         hPen );
   }
}
