#ifndef HBDOCKTREESPLITFIND_H
#define HBDOCKTREESPLITFIND_H

#include <windows.h>

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_LAYOUT_NODE * hbDockTreeFindSplitterAt(
   HB_DOCK_LAYOUT_NODE * pNode,
   POINT pt );

/*
 * Etapa 48: expuesta (antes static, solo usada internamente aca) para
 * que el pintado del splitter (ver hbDockHostPaintSplitters en
 * hbdockhost.c) calcule el rect exacto de cada splitter con la MISMA
 * logica que el hit-test -- sin esto, cualquier ajuste futuro al
 * calculo (por ejemplo, si HBDOCK_SPLITTER_WIDTH cambia, o si se
 * ajusta el redondeo) requeriria tocar dos lugares en vez de uno.
 */
void hbDockNodeSplitterRect(
   const HB_DOCK_LAYOUT_NODE * pNode,
   RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif