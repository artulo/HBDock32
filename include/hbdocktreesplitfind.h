#ifndef HBDOCKTREESPLITFIND_H
#define HBDOCKTREESPLITFIND_H

#include <windows.h>

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Recorre el arbol buscando el nodo split cuyo separador
 * (calculado a partir de Node->Rect + SplitPos + SplitterSize)
 * contiene el punto pt. Devuelve NULL si ninguno coincide.
 */
HB_DOCK_NODE * hbDockTreeFindSplitterAt(
   HB_DOCK_NODE * pNode,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif
