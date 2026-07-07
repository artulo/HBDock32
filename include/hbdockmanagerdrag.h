#ifndef HBDOCKMANAGERDRAG_H
#define HBDOCKMANAGERDRAG_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockpanel.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Inicia el arrastre de pPanel. El panel se desacopla de
 * inmediato del arbol (igual que Visual Studio: el hueco
 * se cierra apenas empieza el drag) y queda "flotando"
 * de forma logica hasta hbDockManagerEndDrag().
 */
void hbDockManagerBeginDrag(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt );

/*
 * Actualiza la posicion del cursor durante el arrastre:
 * recalcula las guias de acople contra lo que queda del
 * arbol y decide el sitio de acople actual (o NONE).
 * Devuelve 1 si hay overlay de preview que redibujar.
 */
int hbDockManagerDragMove(
   HB_DOCK_MANAGER * pManager,
   POINT pt );

/*
 * Finaliza el arrastre en el punto pt:
 * - Si hay un sitio de acople activo, reinserta el panel
 *   en el arbol en ese lugar.
 * - Si no (se solto fuera de cualquier guia), el panel
 *   pasa a ser una ventana flotante independiente.
 */
void hbDockManagerEndDrag(
   HB_DOCK_MANAGER * pManager,
   POINT pt );

/* Cancela el arrastre en curso, restaurando el panel a su
 * posicion original en el arbol. */
void hbDockManagerCancelDrag(
   HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif
