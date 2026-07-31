#ifndef HBDOCKTHEME_H
#define HBDOCKTHEME_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 81: soporte de gradiente en HASTA 2 segmentos -- como el
 * bClrGrad de FiveWin (Gradient2000: { fraccion, colorDesde,
 * colorHasta }, uno o dos de estos por variante). Fraction1 es que
 * proporcion de la altura total ocupa el PRIMER segmento (0..1); si
 * Fraction1 >= 1.0, el segundo segmento no se usa (gradiente simple
 * de un solo tramo).
 */
typedef struct
{
   float Fraction1;
   COLORREF Top1;
   COLORREF Bottom1;
   COLORREF Top2;
   COLORREF Bottom2;

} HB_DOCK_GRADIENT;

typedef struct _HB_DOCK_THEME
{
   COLORREF Background;
   COLORREF Border;
   COLORREF Caption;
   COLORREF CaptionText;
   COLORREF TabActive;
   COLORREF TabInactive;
   COLORREF Guide;

   /*
    * Etapa 80: pedido explicito -- temas visuales (Office 2007/2010/
    * 2015). Este struct ya existia (con los 7 campos de arriba) pero
    * era codigo muerto -- pertenecia a un sistema de arbol paralelo
    * (HB_DOCK_NODE/hbDockPaintManager) que nunca se conecto al
    * sistema de layout activo (HB_DOCK_LAYOUT_NODE). Se reusa la
    * misma estructura (para no duplicar otra en paralelo) y se le
    * agregan los campos que hacian falta para el pintado REAL.
    *
    * Etapa 81: pedido explicito -- usar la paleta REAL de FiveWin
    * (Gradient2000, ver hbdocktheme.c) en vez de una inventada.
    * CaptionGrad/TabInactiveGrad son los gradientes REALES
    * (potencialmente 2 segmentos); Caption/CaptionBottom/TabInactive
    * quedan como el PRIMER color de cada uno (compatibilidad /
    * fallback simple para lo que no necesita el detalle completo).
    */
   COLORREF CaptionBottom;
   COLORREF TabInactiveText;
   COLORREF SplitterBg;
   COLORREF TabSeparator;

   HB_DOCK_GRADIENT CaptionGrad;
   HB_DOCK_GRADIENT TabInactiveGrad;

} HB_DOCK_THEME;

/*
 * Etapa 80: temas con nombre, con paleta propia cada uno.
 */
typedef enum
{
   HBDOCK_THEME_OFFICE2007 = 0,
   HBDOCK_THEME_OFFICE2010,
   HBDOCK_THEME_OFFICE2015

} HB_DOCK_THEME_ID;

void hbDockThemeDefault(
   HB_DOCK_THEME * pTheme );

/*
 * Llena pTheme con la paleta del tema pedido (ThemeId).
 */
void hbDockThemeGetById(
   HB_DOCK_THEME_ID ThemeId,
   HB_DOCK_THEME * pTheme );

/*
 * Tema "actual" -- global de proceso (HBDock32 esta pensado para un
 * manager por aplicacion). Todo el pintado real (caption, tabs,
 * splitters, autohide) lee de aca.
 */
void hbDockThemeSetCurrent(
   HB_DOCK_THEME_ID ThemeId );

HB_DOCK_THEME_ID hbDockThemeGetCurrentId( void );

const HB_DOCK_THEME * hbDockThemeGetCurrent( void );

#ifdef __cplusplus
}
#endif

#endif