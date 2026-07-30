#ifndef HBDOCKAUTOHIDEMANAGER_H
#define HBDOCKAUTOHIDEMANAGER_H

#include <windows.h>

#include "hbdockarray.h"
#include "hbdockpanel.h"
#include "hbdockautohidepane.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HWND hOwner;

   HB_DOCK_ARRAY Panes;

   /*
    * Etapa 58: pedido explicito -- cuando un panel autohide se
    * expande (al pasar el mouse), debe mostrar su caption real (con
    * pin funcional para reactivarlo de forma permanente). Ventana
    * unica y reutilizable (solo un panel puede estar expandido a la
    * vez) -- ver hbdockautohideexpandcaption.c.
    */
   HWND hExpandCaptionWnd;

} HB_DOCK_AUTOHIDE_MANAGER;

void hbDockAutoHideManagerInit(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   HWND hOwner );

void hbDockAutoHideManagerDestroy(
   HB_DOCK_AUTOHIDE_MANAGER * pManager );

int hbDockAutoHideManagerAdd(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane );

int hbDockAutoHideManagerRemove(
   HB_DOCK_AUTOHIDE_MANAGER * pManager,
   void * pPane );

int hbDockAutoHideManagerCount(
   const HB_DOCK_AUTOHIDE_MANAGER * pManager );

#ifdef __cplusplus
}
#endif

#endif