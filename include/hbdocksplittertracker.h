#ifndef HBDOCKSPLITTERTRACKER_H
#define HBDOCKSPLITTERTRACKER_H

#include "hbdocksplitnode.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_SPLIT_NODE * Split;

   POINT StartPoint;

   /*
    * Etapa 50 (fix): reemplaza al viejo "int OriginalPos" -- ese
    * campo leia pSplit->Node->SplitPos, un valor de un sistema de
    * arbol paralelo/legacy (ver hbdocktree.c, hbdocktreeinsert.c)
    * que nunca se mantiene sincronizado con el Ratio real que usa el
    * layout activo, y ademas nunca se usaba despues de asignarse.
    * OriginalRatio en cambio SI se usa: es el ratio real al momento
    * de EMPEZAR el arrastre, necesario para no componer el
    * desplazamiento sobre si mismo en cada WM_MOUSEMOVE (ver
    * hbDockSplitNodeMove).
    */
   float OriginalRatio;

   int Tracking;

} HB_DOCK_SPLITTER_TRACKER;

void hbDockSplitterTrackerInit(
   HB_DOCK_SPLITTER_TRACKER * pTracker );

void hbDockSplitterTrackerBegin(
   HB_DOCK_SPLITTER_TRACKER * pTracker,
   HB_DOCK_SPLIT_NODE * pSplit,
   POINT pt );

void hbDockSplitterTrackerMove(
   HB_DOCK_SPLITTER_TRACKER * pTracker,
   POINT pt );

void hbDockSplitterTrackerEnd(
   HB_DOCK_SPLITTER_TRACKER * pTracker );

#ifdef __cplusplus
}
#endif

#endif