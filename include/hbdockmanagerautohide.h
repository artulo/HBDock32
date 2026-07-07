#ifndef HBDOCKMANAGERAUTOHIDE_H
#define HBDOCKMANAGERAUTOHIDE_H

#include <windows.h>

#include "hbdockmanager.h"
#include "hbdockpanel.h"
#include "hbdockautohide.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Saca a pPanel del arbol de docking y lo repliega contra
 * el borde que tenia como DockSite, dejando solo una franja
 * (pestana) visible de HBDOCK_AUTOHIDE_STRIP pixeles.
 */
void hbDockManagerAutoHidePanel(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

/*
 * Vuelve a acoplar en el arbol un panel que estaba en
 * autohide, en el mismo lado (DockSite) que tenia antes.
 */
void hbDockManagerAutoHideRestore(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

/* Expande temporalmente (sin acoplar) un panel en autohide,
 * tipicamente al pasar el mouse sobre su pestana. */
void hbDockManagerAutoHideExpand(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

/* Repliega de nuevo un panel previamente expandido. */
void hbDockManagerAutoHideCollapse(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_PANEL * pPanel );

/*
 * Hit-test sobre las pestanas de autohide (HiddenRect).
 * Devuelve el panel bajo pt, o NULL.
 */
HB_DOCK_PANEL * hbDockManagerAutoHideHitTest(
   HB_DOCK_MANAGER * pManager,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif
