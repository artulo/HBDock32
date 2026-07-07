#ifndef HBDOCKMANAGERDOCK_H
#define HBDOCKMANAGERDOCK_H

#include "hbdockmanager.h"
#include "hbdockdocksite.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Inserta pPanel dentro del arbol del manager, acoplado
 * al lado (Site) de pTargetNode. Si pTargetNode es NULL
 * (arbol vacio), pPanel se convierte en el nuevo Root.
 *
 * A diferencia de hbDockInsertPanel() (nivel arbol), esta
 * funcion sí reconecta el nuevo split con el Parent original
 * de pTargetNode y actualiza pManager->LayoutEngine.Root
 * cuando corresponde.
 */
HB_DOCK_NODE * hbDockManagerDockPanelAt(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_NODE * pTargetNode,
   HB_DOCK_PANEL * pPanel,
   HB_DOCK_SITE Site );

/*
 * Quita del arbol el nodo hoja que contiene pPanel,
 * promocionando a su hermano en el lugar del split
 * eliminado. Actualiza Root si hace falta. No libera
 * pPanel, solo el nodo hoja/split de arbol.
 *
 * Devuelve 1 si el panel estaba en el arbol y fue
 * removido, 0 si no se encontro.
 */
int hbDockManagerUndockPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

#ifdef __cplusplus
}
#endif

#endif
