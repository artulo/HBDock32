#ifndef HBDOCKDOCKSITE_H
#define HBDOCKDOCKSITE_H

#include <windows.h>

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCKSITE_NONE = 0,
   HB_DOCKSITE_LEFT,
   HB_DOCKSITE_RIGHT,
   HB_DOCKSITE_TOP,
   HB_DOCKSITE_BOTTOM,
   HB_DOCKSITE_CENTER

} HB_DOCK_SITE;

typedef struct
{
   HB_DOCK_NODE * Node;

   HB_DOCK_SITE Site;

   RECT Rect;

} HB_DOCK_DOCKSITE;

void hbDockSiteInit(
   HB_DOCK_DOCKSITE * pSite );

void hbDockSiteCalc(
   HB_DOCK_DOCKSITE * pSite,
   HB_DOCK_NODE * pNode,
   HB_DOCK_SITE Site );

int hbDockSiteHitTest(
   const HB_DOCK_DOCKSITE * pSite,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif