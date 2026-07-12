#ifndef HBDOCKLAYOUTCONTAINER_H
#define HBDOCKLAYOUTCONTAINER_H

#include "hbdocklayouttree.h"
#include "hbdockcontainer.h"

#ifdef __cplusplus
extern "C" {
#endif

void hbDockLayoutAttachContainer(
      HB_DOCK_LAYOUT_NODE * pNode,
      HB_DOCK_CONTAINER * pContainer );

HB_DOCK_CONTAINER *
hbDockLayoutGetContainer(
      const HB_DOCK_LAYOUT_NODE * pNode );

#ifdef __cplusplus
}
#endif

#endif