#ifndef HBDOCKMANAGERFLOAT_H
#define HBDOCKMANAGERFLOAT_H

#include "hbdockmanager.h"
#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerFloat(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_CONTAINER * pContainer,
   const RECT * pRect );

void hbDockManagerFloatPanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT pt );

/*
 * Etapa 42: avisa que un flotante se cerro/oculto -- decrementa el
 * contador y, si llega a 0 (ultimo flotante cerrado), rehabilita la
 * ventana principal. Llamar desde donde sea que un flotante deje de
 * estar visible (cierre con la "x", o "Restaurar"/redock).
 */
void hbDockManagerFloatClosed(
   void * pManager );

/*
 * Etapa 47: drag de un panel YA FLOTANTE de vuelta hacia los
 * diamantes de acoplado (arrastrando la ventana flotante por su
 * titulo). Reciben el punto del cursor en coordenadas de PANTALLA
 * (lo que da GetCursorPos) -- la conversion a coordenadas de cliente
 * de la ventana principal (lo que espera el resto del sistema de
 * drag/guias) se hace internamente. Ver hbdockfloating.c
 * (WM_ENTERSIZEMOVE/WM_MOVING/WM_EXITSIZEMOVE de la ventana
 * flotante), que es quien las llama.
 */
void hbDockManagerFloatDragBegin(
   void * pManager,
   HB_DOCK_PANEL * pPanel,
   POINT ptScreen );

void hbDockManagerFloatDragMove(
   void * pManager,
   POINT ptScreen );

void hbDockManagerFloatDragEnd(
   void * pManager,
   POINT ptScreen );

#ifdef __cplusplus
}
#endif

#endif