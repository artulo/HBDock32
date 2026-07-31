#include "hbdockgradientfill.h"

void hbDockGradientFillVertical(
   HDC hDC,
   const RECT * pRect,
   COLORREF Top,
   COLORREF Bottom )
{
   int y;
   int Height;
   int RTop, GTop, BTop;
   int RBot, GBot, BBot;
   HPEN hPen;
   HPEN hOldPen;

   if( hDC == NULL || pRect == NULL )
      return;

   Height = pRect->bottom - pRect->top;

   if( Height <= 0 )
      return;

   /*
    * Si el degradado es trivial (mismo color arriba y abajo -- temas
    * planos), un solo FillRect alcanza y es mas rapido.
    */
   if( Top == Bottom )
   {
      HBRUSH hBrush;

      hBrush =
         CreateSolidBrush( Top );

      FillRect(
         hDC,
         pRect,
         hBrush );

      DeleteObject(
         hBrush );

      return;
   }

   RTop = GetRValue( Top );
   GTop = GetGValue( Top );
   BTop = GetBValue( Top );

   RBot = GetRValue( Bottom );
   GBot = GetGValue( Bottom );
   BBot = GetBValue( Bottom );

   for( y = 0; y < Height; y++ )
   {
      int R, G, B;
      COLORREF LineColor;

      R = RTop + ( ( RBot - RTop ) * y ) / Height;
      G = GTop + ( ( GBot - GTop ) * y ) / Height;
      B = BTop + ( ( BBot - BTop ) * y ) / Height;

      LineColor = RGB( R, G, B );

      hPen =
         CreatePen(
            PS_SOLID,
            1,
            LineColor );

      hOldPen =
         ( HPEN ) SelectObject(
            hDC,
            hPen );

      MoveToEx(
         hDC,
         pRect->left,
         pRect->top + y,
         NULL );

      LineTo(
         hDC,
         pRect->right,
         pRect->top + y );

      SelectObject(
         hDC,
         hOldPen );

      DeleteObject(
         hPen );
   }
}

/*
 * Etapa 81: ver nota en el header.
 */
void hbDockGradientFillMulti(
   HDC hDC,
   const RECT * pRect,
   const HB_DOCK_GRADIENT * pGrad )
{
   RECT rc1;
   RECT rc2;
   int Height;
   int Split;

   if( hDC == NULL || pRect == NULL || pGrad == NULL )
      return;

   if( pGrad->Fraction1 >= 1.0f || pGrad->Fraction1 <= 0.0f )
   {
      hbDockGradientFillVertical(
         hDC,
         pRect,
         pGrad->Top1,
         pGrad->Bottom1 );

      return;
   }

   Height = pRect->bottom - pRect->top;

   Split =
      pRect->top +
      ( int ) ( ( float ) Height * pGrad->Fraction1 );

   rc1 = *pRect;
   rc1.bottom = Split;

   rc2 = *pRect;
   rc2.top = Split;

   hbDockGradientFillVertical(
      hDC,
      &rc1,
      pGrad->Top1,
      pGrad->Bottom1 );

   hbDockGradientFillVertical(
      hDC,
      &rc2,
      pGrad->Top2,
      pGrad->Bottom2 );
}
