#ifndef HBDOCKPANELFIND_H
#define HBDOCKPANELFIND_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

HB_DOCK_PANEL * hbDockPanelFindById(
   HB_DOCK_NODE * pRoot,
   unsigned int Id );

HB_DOCK_PANEL * hbDockPanelFindByName(
   HB_DOCK_NODE * pRoot,
   const char * pszName );

#ifdef __cplusplus
}
#endif

#endif