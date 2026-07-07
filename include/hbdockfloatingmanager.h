#ifndef HBDOCKFLOATINGMANAGER_H
#define HBDOCKFLOATINGMANAGER_H

#include "hbdockarray.h"
#include "hbdockfloatingframe.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   HB_DOCK_ARRAY Frames;

} HB_DOCK_FLOATING_MANAGER;

void hbDockFloatingManagerInit(
   HB_DOCK_FLOATING_MANAGER * pManager );

void hbDockFloatingManagerDestroy(
   HB_DOCK_FLOATING_MANAGER * pManager );

int hbDockFloatingManagerAdd(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_FRAME * pFrame );

int hbDockFloatingManagerRemove(
   HB_DOCK_FLOATING_MANAGER * pManager,
   HB_DOCK_FLOATING_FRAME * pFrame );

#ifdef __cplusplus
}
#endif

#endif