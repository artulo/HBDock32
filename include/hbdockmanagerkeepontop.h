#ifndef HBDOCKMANAGERKEEPONTOP_H
#define HBDOCKMANAGERKEEPONTOP_H

#include <windows.h>
#include "hbdockmanager.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Engancha la ventana principal (subclassing de su WndProc) para
 * que sus paneles flotantes nunca queden tapados detras de ella al
 * hacer click. Llamar una vez, en hbDockManagerCreate.
 */
BOOL hbDockManagerKeepFloatingOnTopInstall(
   HB_DOCK_MANAGER * pManager );

/*
 * Desengancha y restaura el WndProc original. Llamar en
 * hbDockManagerDestroy, antes de liberar cualquier otra cosa.
 */
void hbDockManagerKeepFloatingOnTopRemove(
   HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif /* HBDOCKMANAGERKEEPONTOP_H */
