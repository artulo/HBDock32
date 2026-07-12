#include <stdio.h>

#include "hbdockpersistcontainer.h"

BOOL hbDockSaveContainer(
      FILE * fp,
      const HB_DOCK_CONTAINER * pContainer )
{
    UINT i;

    if( pContainer == NULL )
    {
        fprintf(
            fp,
            "container-null\n");

        return TRUE;
    }

    fprintf(
        fp,
        "container %d %u\n",
        pContainer->Type,
        pContainer->TabGroup.Count);

    for(i=0;
        i<pContainer->TabGroup.Count;
        i++)
    {
        fprintf(
            fp,
            "%ls\n",
            pContainer->TabGroup.Tabs[i].Caption);
    }

    return TRUE;
}