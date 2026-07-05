#ifndef HBDOCKLAYOUTENGINE_H
#define HBDOCKLAYOUTENGINE_H

#include "hbdocktree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_NODE * Root;

} HB_DOCK_LAYOUT_ENGINE;

void hbDockLayoutEngineInit(
   HB_DOCK_LAYOUT_ENGINE * pEngine );

void hbDockLayoutEngineSetRoot(
   HB_DOCK_LAYOUT_ENGINE * pEngine,
   HB_DOCK_NODE * pRoot );

void hbDockLayoutEnginePerform(
   HB_DOCK_LAYOUT_ENGINE * pEngine,
   const RECT * pRect );

#ifdef __cplusplus
}
#endif

#endif