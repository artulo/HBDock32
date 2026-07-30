#ifndef HBDOCKTABSTRIP_H
#define HBDOCKTABSTRIP_H

#include <windows.h>

#include "hbdocktabgroup.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Etapa 51: "Tabbed Container" -- pedido explicito. Antes de esto,
 * un contenedor con varios paneles tabificados (TabGroup.Count > 1)
 * solo mostraba el caption del panel ACTIVO, ocupando todo el ancho
 * -- sin ninguna tira de pestañas visible/clickeable para cambiar
 * entre ellos, y sin boton de cierre individual funcional (el "x"
 * dibujado en hbDockCaptionDraw es puramente decorativo -- ver
 * hbdockhost.c, WM_LBUTTONDOWN nunca distingue clickear la "x" de
 * clickear cualquier otro lugar del caption).
 *
 * Este modulo agrega esa pieza que faltaba: dado el rect de caption
 * de un contenedor y su TabGroup, calcula/dibuja N segmentos (uno
 * por tab) en vez de un unico caption de ancho completo, cada uno
 * con su propio boton de cerrar.
 */

#define HBDOCK_TAB_CLOSE_SIZE   14

/*
 * Ancho de segmento de cada tab, en pixeles -- fijo y por codigo
 * (facil de ajustar aca si hace falta un tab mas ancho/angosto). Si
 * Count*HBDOCK_TAB_SEGMENT_WIDTH excede el ancho disponible, los
 * segmentos se angostan proporcionalmente para que todos entren.
 */
#define HBDOCK_TAB_SEGMENT_WIDTH   140

/*
 * Rect del segmento del tab en el indice Index (de Count totales),
 * dentro de pCaptionRect.
 */
void hbDockTabStripSegmentRect(
   const RECT * pCaptionRect,
   UINT Count,
   UINT Index,
   RECT * pOut );

/*
 * Indice del tab bajo pt (dentro de pCaptionRect), o -1 si el punto
 * no cae en ningun segmento. Si cae en el boton de cerrar de ESE tab
 * en particular, *pbOnClose queda en TRUE (si no es NULL).
 */
int hbDockTabStripHitTest(
   const HB_DOCK_TAB_GROUP * pGroup,
   const RECT * pCaptionRect,
   POINT pt,
   BOOL * pbOnClose );

/*
 * Dibuja la tira completa de pestañas (una por panel en pGroup)
 * dentro de pCaptionRect -- el activo resaltado, cada uno con su
 * propio texto y boton de cerrar.
 */
void hbDockTabStripDraw(
   HDC hDC,
   const HB_DOCK_TAB_GROUP * pGroup,
   const RECT * pCaptionRect );

#ifdef __cplusplus
}
#endif

#endif
