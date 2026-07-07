#ifndef HBDOCKMANAGERFLOAT_H
#define HBDOCKMANAGERFLOAT_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockpanel.h"
#include "hbdocktree.h"
#include "hbdockdocksite.h"
#include "hbdockfloating.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Convierte pPanel en una ventana flotante independiente,
 * ubicada junto a pt. Si el panel estaba acoplado en el
 * arbol, se lo desacopla primero. No hace nada si el panel
 * ya es flotante.
 */
void hbDockManagerFloatPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt );

/*
 * Vuelve a acoplar un panel flotante dentro del arbol,
 * junto a pTargetNode en el lado Site. Destruye la
 * ventana flotante asociada.
 */
void hbDockManagerDockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_NODE * pTargetNode,
   HB_DOCK_SITE Site );

/* Devuelve la ventana flotante asociada a pPanel, o NULL. */
HB_DOCK_FLOATING * hbDockManagerFindFloating(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif
