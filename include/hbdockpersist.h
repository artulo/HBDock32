#ifndef HBDOCKPERSIST_H
#define HBDOCKPERSIST_H

#include <windows.h>

#include "hbdocklayouttree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    HB_DOCK_FORMAT_XML = 0,
    HB_DOCK_FORMAT_JSON,
    HB_DOCK_FORMAT_BINARY

} HB_DOCK_SAVE_FORMAT;

BOOL hbDockSaveLayout(
    const HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile,
    HB_DOCK_SAVE_FORMAT Format );

BOOL hbDockLoadLayout(
    HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile );

#ifdef __cplusplus
}
#endif

#endif