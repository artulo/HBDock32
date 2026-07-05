#ifndef HBDOCKHITTEST_H
#define HBDOCKHITTEST_H

#include <windows.h>

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
   HB_DOCK_HIT_NONE = 0,
   HB_DOCK_HIT_PANEL,
   HB_DOCK_HIT_SPLITTER

} HB_DOCK_HIT;

typedef struct
{
   HB_DOCK_HIT Hit;

   HB_DOCK_PANEL * Panel;

   HB_DOCK_NODE * Node;

} HB_DOCK_HITTEST;

void hbDockHitTestInit(
   HB_DOCK_HITTEST * pHit );

void hbDockHitTestTree(
   HB_DOCK_NODE * pRoot,
   POINT pt,
   HB_DOCK_HITTEST * pHit );

#ifdef __cplusplus
}
#endif

#endif