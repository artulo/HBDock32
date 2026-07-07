#ifndef HBDOCKHOST_H
#define HBDOCKHOST_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdocksplitnode.h"
#include "hbdocksplittertracker.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HBDOCK_AUTOHIDE_TIMER_ID   ( 0x4844 )
#define HBDOCK_AUTOHIDE_TIMER_MS   200

typedef struct _HB_DOCK_HOST
{
   HWND hWnd;
   HB_DOCK_MANAGER * pManager;

   /* Candidato a arrastre: boton bajado sobre un caption,
    * pero todavia no supero el umbral de movimiento. */
   HB_DOCK_PANEL * PendingDragPanel;
   POINT PendingDragPoint;

   int Dragging;

   /* Splitter actualmente en arrastre, si hay uno.
    * ActiveSplit debe vivir mientras dure el arrastre,
    * ya que SplitterTracker solo guarda un puntero a el. */
   HB_DOCK_SPLIT_NODE ActiveSplit;
   HB_DOCK_SPLITTER_TRACKER SplitterTracker;

   /* Panel de autohide expandido por hover, para poder
    * replegarlo cuando el mouse se va. */
   HB_DOCK_PANEL * HoverAutoHide;

} HB_DOCK_HOST;

BOOL hbDockHostAttach(
   HB_DOCK_HOST * pHost,
   HWND hWnd,
   HB_DOCK_MANAGER * pManager );

void hbDockHostDetach(
   HB_DOCK_HOST * pHost );

void hbDockHostResize(
   HB_DOCK_HOST * pHost );

void hbDockHostInvalidate(
   HB_DOCK_HOST * pHost );

/*
 * Procesa un mensaje de ventana relacionado con la
 * interaccion de docking (mouse y timer). Pensada para
 * ser llamada desde el WndProc del host (o desde el
 * despachador de mensajes de FiveWin/Harbour que lo
 * envuelva).
 *
 * Devuelve TRUE si el mensaje fue consumido por el
 * docking (en cuyo caso el llamador normalmente no debe
 * seguir procesandolo / puede devolver 0 directamente).
 */
BOOL hbDockHostHandleMessage(
   HB_DOCK_HOST * pHost,
   UINT uMsg,
   WPARAM wParam,
   LPARAM lParam );

#ifdef __cplusplus
}
#endif

#endif