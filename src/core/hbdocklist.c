#include <stdlib.h>
 
#include "hbdocklist.h"

void hbDockListInit(
   HB_DOCK_LIST * pList )
{
   if( pList == NULL )
      return;

   pList->First = NULL;
   pList->Last  = NULL;
   pList->Count = 0;
}

HB_DOCK_NODE * hbDockListAppend(
   HB_DOCK_LIST * pList,
   void * Data )
{
   HB_DOCK_NODE * pNode;

   if( pList == NULL )
      return NULL;

   pNode = ( HB_DOCK_NODE * )
      malloc(
         sizeof( HB_DOCK_NODE ) );

   if( pNode == NULL )
      return NULL;

   pNode->Data = Data;
   pNode->Next = NULL;
   pNode->Prev = pList->Last;

   if( pList->Last != NULL )
      pList->Last->Next = pNode;
   else
      pList->First = pNode;

   pList->Last = pNode;

   pList->Count++;

   return pNode;
}

HB_DOCK_NODE * hbDockListPrepend(
   HB_DOCK_LIST * pList,
   void * Data )
{
   HB_DOCK_NODE * pNode;

   if( pList == NULL )
      return NULL;

   pNode = ( HB_DOCK_NODE * )
      malloc(
         sizeof( HB_DOCK_NODE ) );

   if( pNode == NULL )
      return NULL;

   pNode->Data = Data;
   pNode->Prev = NULL;
   pNode->Next = pList->First;

   if( pList->First != NULL )
      pList->First->Prev = pNode;
   else
      pList->Last = pNode;

   pList->First = pNode;

   pList->Count++;

   return pNode;
}

void hbDockListRemove(
   HB_DOCK_LIST * pList,
   HB_DOCK_NODE * pNode )
{
   if( pList == NULL || pNode == NULL )
      return;

   if( pNode->Prev != NULL )
      pNode->Prev->Next = pNode->Next;
   else
      pList->First = pNode->Next;

   if( pNode->Next != NULL )
      pNode->Next->Prev = pNode->Prev;
   else
      pList->Last = pNode->Prev;

   free(
      pNode );

   if( pList->Count > 0 )
      pList->Count--;
}

void hbDockListClear(
   HB_DOCK_LIST * pList )
{
   HB_DOCK_NODE * pNode;
   HB_DOCK_NODE * pNext;

   if( pList == NULL )
      return;

   pNode = pList->First;

   while( pNode != NULL )
   {
      pNext = pNode->Next;

      free(
         pNode );

      pNode = pNext;
   }

   pList->First = NULL;
   pList->Last  = NULL;
   pList->Count = 0;
}