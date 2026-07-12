#include "hbdockpersist.h"

#include "hbdockpersistxml.h"
#include "hbdockpersistjson.h"
#include "hbdockpersistbin.h"

BOOL hbDockSaveLayout(
    const HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile,
    HB_DOCK_SAVE_FORMAT Format )
{
    switch( Format )
    {
        case HB_DOCK_FORMAT_XML:

            return hbDockSaveXML(
                pTree,
                pszFile );

        case HB_DOCK_FORMAT_JSON:

            return hbDockSaveJSON(
                pTree,
                pszFile );

        case HB_DOCK_FORMAT_BINARY:

            return hbDockSaveBinary(
                pTree,
                pszFile );
    }

    return FALSE;
}

BOOL hbDockLoadLayout(
    HB_DOCK_LAYOUT_TREE * pTree,
    LPCTSTR pszFile )
{
    /* detección automática */

    return hbDockLoadXML(
        pTree,
        pszFile );
}