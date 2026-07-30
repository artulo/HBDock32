#ifndef HBDOCKAUTOHIDEEXPANDCAPTION_H
#define HBDOCKAUTOHIDEEXPANDCAPTION_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 58: pedido explicito -- cuando un panel autohide se expande
 * (al pasar el mouse sobre su pestaña), debe mostrar su caption
 * real, con el pin ("o") funcional para reactivarlo de forma
 * PERMANENTE (redockearlo, no solo mostrarlo temporalmente) y la
 * "x" para replegarlo de nuevo. Ventana unica y reutilizable (solo
 * un panel puede estar expandido a la vez en la practica).
 *
 * pRect es el rect de la franja de caption en si (arriba del panel
 * expandido), en coordenadas de cliente de la ventana principal --
 * el llamador es responsable de reservar ese espacio (no superponer
 * con el contenido real del panel).
 */
void hbDockAutoHideExpandCaptionShow(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   const RECT * pRect );

void hbDockAutoHideExpandCaptionHide(
   HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif
