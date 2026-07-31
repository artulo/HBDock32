#include <windows.h>

#include "hbdockcaption.h"
#include "hbdockpanel.h"
#include "hbdocktheme.h"
#include "hbdockgradientfill.h"

void hbDockCaptionInit(
   HB_DOCK_CAPTION * pCaption,
   HB_DOCK_PANEL * pPanel )
{
   if( pCaption == NULL )
      return;

   ZeroMemory(
      pCaption,
      sizeof( HB_DOCK_CAPTION ) );

   pCaption->Panel = pPanel;
}

void hbDockCaptionLayout(
   HB_DOCK_CAPTION * pCaption,
   const RECT * pRect )
{
   if( pCaption == NULL )
      return;

   if( pRect == NULL )
      return;

   pCaption->Rect = *pRect;

   SetRect(
      &pCaption->CloseRect,
      pRect->right - 20,
      pRect->top + 2,
      pRect->right - 2,
      pRect->top + 20 );

   SetRect(
      &pCaption->PinRect,
      pRect->right - 40,
      pRect->top + 2,
      pRect->right - 22,
      pRect->top + 20 );
}

/*
 * Nota de estabilizacion (Etapa 18): esta funcion existia pero solo
 * dibujaba 3 rectangulos vacios con la pluma/pincel por default
 * (negro sobre blanco) -- ni color, ni texto, ni iconos. Sin ningun
 * indicio visual de donde esta el caption, era imposible saber donde
 * hacer click para arrastrar un panel (aunque el hit-test ya
 * funcionara bien). Se completa: relleno azul (mismo tono que las
 * guias/diamante, para consistencia visual), texto del panel en
 * blanco, y una "x"/pin simples para cerrar/autohide.
 */
void hbDockCaptionDraw(
   HDC hDC,
   HB_DOCK_CAPTION * pCaption )
{
   HBRUSH hOldBrush;
   HPEN hPen;
   HPEN hOldPen;
   COLORREF OldTextColor;
   int OldBkMode;

   if( hDC == NULL )
      return;

   if( pCaption == NULL )
      return;

   /*
    * Etapa 80/81: fondo del caption -- degradado del tema actual
    * (hasta 2 segmentos, paleta real de FiveWin/Gradient2000).
    */
   {
      const HB_DOCK_THEME * pTheme =
         hbDockThemeGetCurrent();

      hbDockGradientFillMulti(
         hDC,
         &pCaption->Rect,
         &pTheme->CaptionGrad );
   }

   /* Texto del panel, si hay uno registrado. */
   if( pCaption->Panel != NULL &&
       pCaption->Panel->Caption[ 0 ] != '\0' )
   {
      RECT rcText;

      rcText = pCaption->Rect;
      rcText.left += 6;
      rcText.right = pCaption->PinRect.left - 4;

      if( rcText.right < rcText.left )
         rcText.right = rcText.left;

      OldTextColor =
         SetTextColor(
            hDC,
            hbDockThemeGetCurrent()->CaptionText );

      OldBkMode =
         SetBkMode(
            hDC,
            TRANSPARENT );

      DrawText(
         hDC,
         pCaption->Panel->Caption,
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

   /* Boton de cierre: una "x" simple. */
   hPen =
      CreatePen(
         PS_SOLID,
         1,
         hbDockThemeGetCurrent()->CaptionText );

   hOldPen =
      ( HPEN ) SelectObject(
         hDC,
         hPen );

   MoveToEx(
      hDC,
      pCaption->CloseRect.left + 4,
      pCaption->CloseRect.top + 4,
      NULL );

   LineTo(
      hDC,
      pCaption->CloseRect.right - 4,
      pCaption->CloseRect.bottom - 4 );

   MoveToEx(
      hDC,
      pCaption->CloseRect.right - 4,
      pCaption->CloseRect.top + 4,
      NULL );

   LineTo(
      hDC,
      pCaption->CloseRect.left + 4,
      pCaption->CloseRect.bottom - 4 );

   /* Boton de autohide: un pequeño pin (circulo). */
   hOldBrush =
      ( HBRUSH ) SelectObject(
         hDC,
         GetStockObject( NULL_BRUSH ) );

   Ellipse(
      hDC,
      pCaption->PinRect.left + 4,
      pCaption->PinRect.top + 4,
      pCaption->PinRect.right - 4,
      pCaption->PinRect.bottom - 4 );

   SelectObject(
      hDC,
      hOldBrush );

   SelectObject(
      hDC,
      hOldPen );

   DeleteObject(
      hPen );
}
