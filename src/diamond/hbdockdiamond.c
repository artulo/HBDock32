#include <windows.h>

#include "hbdockdiamond.h"

void hbDockDiamondMove(
   HB_DOCK_DIAMOND * pDiamond,
   POINT pt )
{
   LONG Size;
   LONG Offset;

   if( pDiamond == NULL )
      return;

   Size = 28;
   Offset = 40;

   SetRect(
      &pDiamond->CenterRect,
      pt.x - Size / 2,
      pt.y - Size / 2,
      pt.x + Size / 2,
      pt.y + Size / 2 );

   pDiamond->LeftRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->LeftRect,
      -Offset,
      0 );

   pDiamond->RightRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->RightRect,
      Offset,
      0 );

   pDiamond->TopRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->TopRect,
      0,
      -Offset );

   pDiamond->BottomRect = pDiamond->CenterRect;
   OffsetRect(
      &pDiamond->BottomRect,
      0,
      Offset );

   /*
    * Etapa 17: pDiamond->Rect (la union de las 5 zonas de arriba) no
    * se calculaba nunca -- sin ella, nadie podia reposicionar la
    * ventana real del diamante (pDiamond->hWnd), que se quedaba
    * fija donde se creo por primera vez sin importar donde estuviera
    * el mouse. El hit-test (hbDockDiamondHitTest) seguia funcionando
    * igual porque compara pt contra los 5 rects de arriba
    * directamente, no contra la ventana real -- pero visualmente el
    * diamante nunca aparecia donde correspondia. hbDockGuideManagerMove
    * (el llamador) usa este rect para el MoveWindow real, convertido
    * a coordenadas de pantalla.
    */
   SetRect(
      &pDiamond->Rect,
      pt.x - Offset - Size / 2,
      pt.y - Offset - Size / 2,
      pt.x + Offset + Size / 2,
      pt.y + Offset + Size / 2 );
}
