#ifndef HBDOCKGUIDEMANAGER_H
#define HBDOCKGUIDEMANAGER_H

#include <windows.h>

#include "hbdockdiamond.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_GUIDE_NONE = 0,

   HB_GUIDE_LEFT,

   HB_GUIDE_RIGHT,

   HB_GUIDE_TOP,

   HB_GUIDE_BOTTOM,

   HB_GUIDE_CENTER

} HB_DOCK_GUIDE_TYPE;

typedef struct _HB_DOCK_GUIDE
{
   HWND hWnd;

   RECT Rect;

   HB_DOCK_GUIDE_TYPE Type;

   BOOL Visible;

} HB_DOCK_GUIDE;

typedef struct _HB_DOCK_GUIDE_MANAGER
{
   HWND hParent;

   BOOL Visible;

   HB_DOCK_GUIDE Left;

   HB_DOCK_GUIDE Right;

   HB_DOCK_GUIDE Top;

   HB_DOCK_GUIDE Bottom;

   HB_DOCK_GUIDE Center;

   HB_DOCK_DIAMOND Diamond;

} HB_DOCK_GUIDE_MANAGER;

BOOL hbDockGuideManagerCreate(
   HB_DOCK_GUIDE_MANAGER * pManager,
   HWND hParent );

void hbDockGuideManagerDestroy(
   HB_DOCK_GUIDE_MANAGER * pManager );

void hbDockGuideManagerShow(
   HB_DOCK_GUIDE_MANAGER * pManager );

void hbDockGuideManagerHide(
   HB_DOCK_GUIDE_MANAGER * pManager );

void hbDockGuideManagerMove(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt );

/*
 * Etapa 20: separa el movimiento en dos responsabilidades distintas
 * (antes hbDockGuideManagerMove hacia las dos juntas, siguiendo el
 * mouse en ambos casos -- no coincide con el diseño de referencia,
 * donde las 4 guias externas quedan FIJAS cerca de los bordes de la
 * ventana principal durante todo el arrastre, y solo el diamante
 * central sigue al panel que se esta sobrevolando).
 *
 * hbDockGuideManagerPositionOuter: posiciona Left/Right/Top/Bottom
 * una vez, cerca de los bordes de pClient (llamar al iniciar el
 * arrastre, no en cada movimiento del mouse).
 *
 * hbDockGuideManagerMoveDiamond: mueve SOLO el diamante, centrado en
 * ptCenter (el centro del panel bajo el mouse, no el mouse en si).
 */
void hbDockGuideManagerPositionOuter(
   HB_DOCK_GUIDE_MANAGER * pManager,
   const RECT * pClient );

void hbDockGuideManagerMoveDiamond(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT ptCenter );

HB_DOCK_GUIDE_TYPE hbDockGuideManagerHitTest(
   const HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt );

/*
 * Etapa 20: igual que HitTest, pero ademas informa si el resultado
 * vino del diamante (acoplar relativo a un panel puntual) o de una
 * guia externa (acoplar relativo a toda la ventana).
 */
HB_DOCK_GUIDE_TYPE hbDockGuideManagerHitTestEx(
   const HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt,
   BOOL * pFromDiamond );

BOOL hbDockGuideManagerVisible(
   const HB_DOCK_GUIDE_MANAGER * pManager );

/*
 * Nota de estabilizacion: se llama desde hbdockengine.c (motor
 * alternativo, ver notas de Etapas 2/4/5 sobre el arbol de codigo
 * desconectado). Las guias reales son ventanas propias (creadas via
 * hbDockGuideWindowCreate) que Windows ya repinta solas con su propio
 * WM_PAINT -- no hace falta pintarlas manualmente desde afuera, asi
 * que esta funcion no tiene nada que hacer hoy. Se declara e
 * implementa como no-op para que el arbol compile completo.
 */
void hbDockGuideManagerPaint(
   const HB_DOCK_GUIDE_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif