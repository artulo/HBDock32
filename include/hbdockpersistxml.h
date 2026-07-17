#ifndef HBDOCKPERSISTXML_H
#define HBDOCKPERSISTXML_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockSaveXML(
    const HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile );

BOOL hbDockLoadXML(
    HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile );

#ifdef __cplusplus
}
#endif

#endif
