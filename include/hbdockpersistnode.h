#ifndef HBDOCKPERSISTNODE_H
#define HBDOCKPERSISTNODE_H

#include <windows.h>

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockSaveNode(
      FILE * fp,
      const HB_DOCK_LAYOUT_NODE * pNode );

BOOL hbDockLoadNode(
      FILE * fp,
      HB_DOCK_LAYOUT_NODE ** ppNode );

#ifdef __cplusplus
}
#endif

#endif