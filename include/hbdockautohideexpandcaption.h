#ifndef HBDOCKAUTOHIDEEXPANDCAPTION_H
#define HBDOCKAUTOHIDEEXPANDCAPTION_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 79: rediseno -- ver nota completa en
 * src/manager/hbdockautohideexpandcaption.c. Ahora es una ventana
 * WS_POPUP real (no WS_CHILD) que hospeda el CONTENIDO del panel
 * REPARENTADO adentro suyo mientras esta expandido -- z-order
 * confiable de forma nativa, sin competir con sus hermanos acoplados.
 *
 * pRectScreen es el rect COMPLETO (franja de caption + contenido),
 * en coordenadas de PANTALLA (una popup se posiciona en pantalla, no
 * relativo a un padre) -- el llamador debe convertir con
 * ClientToScreen antes de llamar.
 */
void hbDockAutoHideExpandCaptionShow(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   const RECT * pRectScreen );

/*
 * Etapa 79: reposiciona/redimensiona la popup YA MOSTRADA (durante
 * cada tick de la animacion de expansion) -- mismo rect (coordenadas
 * de pantalla) que Show, pero sin reparentar de nuevo.
 */
void hbDockAutoHideOverlayReposition(
   HB_DOCK_MANAGER * pManager,
   const RECT * pRectScreen );

void hbDockAutoHideExpandCaptionHide(
   HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif
