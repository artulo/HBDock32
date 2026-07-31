#ifndef HBDOCKGRADIENTFILL_H
#define HBDOCKGRADIENTFILL_H

#include <windows.h>

#include "hbdocktheme.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 80: pedido explicito -- temas con degradado (Office 2007/
 * 2010). En vez de depender de GradientFill() (msimg32.dll -- riesgo
 * real de que no este disponible/enlazado en BCC770), se interpola
 * a mano dibujando lineas horizontales -- portable, sin libs
 * externas nuevas.
 */
void hbDockGradientFillVertical(
   HDC hDC,
   const RECT * pRect,
   COLORREF Top,
   COLORREF Bottom );

/*
 * Etapa 81: version de hasta 2 segmentos (como Gradient2000 de
 * FiveWin) -- pRect se divide en 2 tramos segun pGrad->Fraction1
 * (0..1, que proporcion de la altura ocupa el primer tramo), cada
 * uno con su propio degradado interno. Si Fraction1 >= 1.0, se
 * dibuja como un unico tramo simple (equivalente a llamar
 * hbDockGradientFillVertical con Top1/Bottom1).
 */
void hbDockGradientFillMulti(
   HDC hDC,
   const RECT * pRect,
   const HB_DOCK_GRADIENT * pGrad );

#ifdef __cplusplus
}
#endif

#endif
