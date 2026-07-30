#ifndef HBDOCKAUTOHIDEANIMATIONMANAGERTICK_H
#define HBDOCKAUTOHIDEANIMATIONMANAGERTICK_H

#include "hbdockautohideanimationmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 59: pManager (opaco, HB_DOCK_MANAGER* -- void* para evitar
 * cualquier riesgo de include circular desde este header) se agrego
 * para poder mostrar el caption del panel una vez que termina de
 * expandirse por el camino ANIMADO (antes solo el camino NO animado
 * mostraba el caption -- ver hbdockmanagerautohide.c, Etapa 58 --
 * pero Animation=TRUE es el default, asi que en la practica el
 * caption nunca se mostraba).
 */
void hbDockAutoHideAnimationManagerTick(
   HB_DOCK_AUTOHIDE_ANIMATION_MANAGER * pManager,
   void * pDockManager );

#ifdef __cplusplus
}
#endif

#endif
