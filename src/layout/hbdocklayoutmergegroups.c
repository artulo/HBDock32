#include "hbdocklayoutmergegroups.h"
#include "hbdockcontainermerge.h"

BOOL hbDockLayoutMergeGroups(
      HB_DOCK_LAYOUT_NODE * pNode )
{
   if( pNode == NULL )
      return FALSE;

   if( pNode->First == NULL )
      return FALSE;

   if( pNode->Second == NULL )
      return FALSE;

   if( pNode->First->pContainer == NULL )
      return FALSE;

   if( pNode->Second->pContainer == NULL )
      return FALSE;

   return hbDockContainerMerge(
      pNode->First->pContainer,
      pNode->Second->pContainer );
}