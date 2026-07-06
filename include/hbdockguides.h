#ifndef HBDOCKGUIDES_H
#define HBDOCKGUIDES_H

#include <windows.h>

#include "hbdockdocksite.h"

#define HB_DOCK_GUIDES_MAX 5

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   int Count;

   HB_DOCK_DOCKSITE Guide[ HB_DOCK_GUIDES_MAX ];

} HB_DOCK_GUIDES;

void hbDockGuidesInit(
   HB_DOCK_GUIDES * pGuides );

void hbDockGuidesBuild(
   HB_DOCK_GUIDES * pGuides,
   HB_DOCK_NODE * pNode );

HB_DOCK_SITE hbDockGuidesHitTest(
   HB_DOCK_GUIDES * pGuides,
   POINT pt );

#ifdef __cplusplus
}
#endif

#endif