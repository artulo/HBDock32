#ifndef HBDOCKPERSISTJSON_H
#define HBDOCKPERSISTJSON_H

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL hbDockSaveJSON(
    const HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile );

BOOL hbDockLoadJSON(
    HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile );

#ifdef __cplusplus
}
#endif

#endif
