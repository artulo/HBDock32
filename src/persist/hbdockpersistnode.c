#include <stdio.h>

#include "hbdockpersistnode.h"

BOOL hbDockSaveNode(
      FILE * fp,
      const HB_DOCK_LAYOUT_NODE * pNode )
{
    if( pNode == NULL )
    {
        fprintf(
            fp,
            "null\n");

        return TRUE;
    }

    fprintf(
        fp,
        "%d %.4f\n",
        pNode->Type,
        pNode->Ratio);

    hbDockSaveNode(
        fp,
        pNode->First);

    hbDockSaveNode(
        fp,
        pNode->Second);

    return TRUE;
}