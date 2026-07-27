#ifndef HBDOCKAUTOHIDEANIMATIONMANAGER_H
#define HBDOCKAUTOHIDEANIMATIONMANAGER_H

#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Nota de estabilizacion: pPanes era HB_DOCK_AUTOHIDE_PANE** (un tipo
 * sin relacion con HB_DOCK_AUTOHIDE), pero hbDockAutoHideAnimationTick
 * y hbDockAutoHideSchedulerTick (los que de verdad recorren este
 * arreglo) operan sobre campos que solo existen en HB_DOCK_AUTOHIDE
 * (Sliding, SlidePosition, SlideDirection, SlideStep) -- pasarles un
 * HB_DOCK_AUTOHIDE_PANE* era una conversion de puntero invalida que
 * el compilador señalaba (W8075). Se corrige el tipo del arreglo
 * para que coincida con lo que sus propios lectores necesitan. Sin
 * llamadores para Add/Remove tampoco, asi que es un cambio seguro.
 */

typedef struct _HB_DOCK_AUTOHIDE_ANIMATION_MANAGER
{
   HB_DOCK_AUTOHIDE ** pPanes;

   int Count;
   int Capacity;

   UINT TimerId;
   UINT Interval;

   BOOL Enabled;
   BOOL Paused;
   BOOL Running;

} HB_DOCK_AUTOHIDE_ANIMATION_MANAGER;

void hbDockAutoHideAnimationManagerInit(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager );

void hbDockAutoHideAnimationManagerDone(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif