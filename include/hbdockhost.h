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
#define HBDOCK_ANIMATION_TIMER_ID  ( 0x4845 )

/*
 * Etapa 30: timer de un solo disparo para forzar el repintado de
 * captions una vez que la ventana principal ya esta completamente
 * activada/visible -- ver hbdockmanagerkeepontop.c. Independiente
 * de TTimer/DEFINE TIMER de FiveWin (que resulto no dispararse de
 * forma confiable en este proyecto): usa el mismo mecanismo
 * SetTimer/WM_TIMER ya comprobado funcionando para AutoHide/animacion.
 */
#define HBDOCK_FIRSTPAINT_TIMER_ID ( 0x4846 )
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

/*
 * Pinta el caption (franja de titulo) del panel activo de cada
 * contenedor acoplado. Llamar desde WM_PAINT del host real, DESPUES
 * de que el WndProc original ya termino su propio pintado (ver
 * hbdockmanagerkeepontop.c).
 */
void hbDockHostPaintCaptions(
   HB_DOCK_HOST * pHost );

/*
 * Etapa 48: pedido explicito -- los splitters no se pintaban de
 * forma distintiva en absoluto (la unica funcion de pintado que
 * existia, hbDockSplitterPaint, no tenia ningun llamador). Recorre
 * el arbol y dibuja un bisel 3D "elevado" (DrawEdge/EDGE_RAISED) en
 * el rect de cada splitter -- llamar desde WM_PAINT de la ventana
 * principal, DESPUES de que el WndProc original ya termino su propio
 * pintado (mismo patron que hbDockHostPaintCaptions).
 */
void hbDockHostPaintSplitters(
   HB_DOCK_HOST * pHost,
   HDC hDC );

/*
 * Etapa 53: pedido explicito -- las pestañas de AutoHide (la franja
 * angosta que queda visible en el borde cuando un panel esta
 * replegado) nunca se pintaban de forma real (la unica funcion de
 * pintado del modulo de autohide, hbDockAutoHideStripPaint, no tenia
 * ningun llamador y ni siquiera dibujaba texto). Recorre
 * pManager->AutoHideManager.Panes y dibuja cada HiddenRect con el
 * nombre real del panel -- texto rotado 90 grados para los lados
 * LEFT/RIGHT (leible de abajo hacia arriba), horizontal para
 * TOP/BOTTOM. Llamar desde WM_PAINT, junto con
 * hbDockHostPaintSplitters/PaintCaptions.
 */
void hbDockHostPaintAutoHideTabs(
   HB_DOCK_HOST * pHost,
   HDC hDC );

#ifdef __cplusplus
}
#endif

#endif