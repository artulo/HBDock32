#ifndef HBDOCKMANAGERRESTORE_H
#define HBDOCKMANAGERRESTORE_H

#include "hbdockmanager.h"
#include "hbdockcontainer.h"
#include "hbdockdocksite.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockManagerRestore(
   HB_DOCK_MANAGER * pManager,
   HB_DOCK_LAYOUT_NODE * pTarget,
   HB_DOCK_CONTAINER * pContainer,
   HB_DOCK_SITE Site );

#ifdef __cplusplus
}
#endif

#endif