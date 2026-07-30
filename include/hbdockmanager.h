#ifndef HBDOCKMANAGER_H
#define HBDOCKMANAGER_H

#include <windows.h>

#include "hbdocklayouttree.h"
#include "hbdockpreviewoverlay.h"
#include "hbdockguidemanager.h"
#include "hbdockdiamond.h"
#include "hbdockautohideanimationmanager.h"
#include "hbdockscheduler.h"
#include "hbdockpanelregistry.h"
#include "hbdockcommandqueue.h"
#include "hbdocktransaction.h"
#include "hbdockeventdispatcher.h"
#include "hbdockautohidemanager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_DRAG_CONTROLLER HB_DOCK_DRAG_CONTROLLER;
typedef struct _HB_DOCK_HOST HB_DOCK_HOST;

typedef struct _HB_DOCK_MANAGER
{
    HWND hMainWnd;

    HB_DOCK_LAYOUT_TREE LayoutTree;

    HB_DOCK_PANEL_REGISTRY Registry;

    HB_DOCK_EVENT_DISPATCHER Dispatcher;

    HB_DOCK_GUIDE_MANAGER GuideManager;

    HB_DOCK_PREVIEW_OVERLAY Preview;

    HB_DOCK_DIAMOND Diamond;

    HB_DOCK_AUTOHIDE_MANAGER AutoHideManager;

    HB_DOCK_AUTOHIDE_ANIMATION_MANAGER AnimationManager;

    HB_DOCK_COMMAND_QUEUE CommandQueue;

    HB_DOCK_TRANSACTION Transaction;

    HB_DOCK_SCHEDULER Scheduler;


    HB_DOCK_DRAG_CONTROLLER * pDragController;

    /*
     * Etapa 15: enganche real de mouse/timer para interaccion de
     * usuario (drag de paneles, splitters, hover de autohide) --
     * toda esta logica ya existia en hbdockhost.c/hbdockdrag*.c
     * pero nada la conectaba a mensajes de ventana reales. Puntero
     * opaco (no struct embebido) para evitar include circular:
     * hbdockhost.h incluye hbdockmanager.h.
     */
    HB_DOCK_HOST * pHost;

    HWND hCapturedWindow;

    /*
     * Etapa 37: HBDock32 no tiene forma de saber que existe una
     * toolbar (u otra barra) ocupando espacio en la ventana
     * principal -- GetClientRect(hMainWnd) devuelve el area COMPLETA
     * de la ventana, sin excluir nada (a diferencia de FiveWin, que
     * SI sabe hacerlo -- ver ClientCoors en tsplitter.prg, usada
     * para calcular el area disponible real considerando
     * oWnd:oTop/oBar/oLeft/oRight/oBottom). Sin este margen, los
     * paneles/captions de HBDock32 podian terminar ocupando el
     * mismo espacio de pantalla que la toolbar. Se establece una
     * vez desde el .prg (justo despues de crear la toolbar) via
     * HBDockSetTopMargin, y se resta SIEMPRE de GetClientRect antes
     * de calcular el area disponible para acoplar paneles.
     */
    int TopMargin;

    /*
     * Etapa 42: cuenta de paneles flotantes actualmente visibles.
     * Mientras sea > 0, la ventana principal queda deshabilitada
     * (comportamiento tipo modal, pedido explicito) -- se rehabilita
     * cuando el ultimo flotante se cierra. Varios flotantes pueden
     * convivir a la vez (no son modales ENTRE si, solo respecto de
     * la ventana principal), por eso es un contador y no un booleano.
     */
    int FloatingCount;

    BOOL Dragging;

    BOOL UpdatingLayout;

} HB_DOCK_MANAGER;

BOOL hbDockManagerCreate(
      HB_DOCK_MANAGER * pManager,
      HWND hWnd );

void hbDockManagerDestroy(
      HB_DOCK_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif