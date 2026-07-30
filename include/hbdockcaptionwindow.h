#ifndef HBDOCKCAPTIONWINDOW_H
#define HBDOCKCAPTIONWINDOW_H

#include <windows.h>

#include "hbdockpanel.h"
#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 24: la franja de caption de cada contenedor pasa a ser una
 * ventana HIJA real y propia (en vez de dibujarse "por encima" desde
 * la ventana principal via GetDC -- ver Etapa 18/22, que quedaban
 * intermitentemente recortadas por el clipping automatico de
 * ventanas hijas de GetDC, tipico cuando la ventana principal tiene
 * WS_CLIPCHILDREN). Cada ventana de caption es "transparente al
 * mouse" (WM_NCHITTEST -> HTTRANSPARENT), asi que los clicks la
 * atraviesan visualmente y siguen llegando a la ventana principal
 * exactamente como antes -- el hit-test de drag (hbdockhost.c) no
 * necesita ningun cambio.
 */

HWND hbDockCaptionWindowCreate(
   HWND hParent );

void hbDockCaptionWindowDestroy(
   HWND hWnd );

/*
 * Reposiciona la ventana de caption sobre pRect (coordenadas de
 * cliente de la ventana principal, mismo sistema que el resto del
 * layout -- es una ventana HIJA, no un popup, asi que NO necesita
 * conversion a pantalla), la sube al frente del z-order (para que
 * nunca quede tapada por el panel), y le asocia el CONTENEDOR (antes
 * solo el panel activo -- Etapa 51: hace falta el contenedor
 * completo para que WM_PAINT pueda acceder a TabGroup y decidir si
 * dibuja un caption simple o una tira de pestañas).
 */
void hbDockCaptionWindowUpdate(
   HWND hWnd,
   const RECT * pRect,
   HB_DOCK_CONTAINER * pContainer );

#ifdef __cplusplus
}
#endif

#endif
