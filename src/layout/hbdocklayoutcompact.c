#include "hbdocklayoutcompact.h"

static void CompactNode(
      HB_DOCK_LAYOUT_NODE * pNode )
{
   if(pNode==NULL)
      return;

   CompactNode(
      pNode->First);

   CompactNode(
      pNode->Second);

   /*
      Próxima fase:

      Si un nodo tiene un solo hijo,
      promover dicho hijo.

      Si ambos hijos son hojas vacías,
      eliminar el nodo.

      Si ambos hijos contienen TabGroups,
      fusionarlos automáticamente.

   */
}

void hbDockLayoutCompact(
      HB_DOCK_LAYOUT_TREE * pTree )
{
   CompactNode(
      pTree->Root);
}