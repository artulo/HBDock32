#include <stdlib.h>
#include <string.h>

#include "hbdockarray.h"

#define HB_DOCK_ARRAY_GROW 16

static int hbDockArrayGrow(
   HB_DOCK_ARRAY * pArray,
   int Capacity )
{
   void ** pItems;

   if( Capacity <= pArray->Capacity )
      return 1;

   pItems = ( void ** ) realloc(
      pArray->Items,
      Capacity * sizeof( void * ) );

   if( pItems == NULL )
      return 0;

   pArray->Items = pItems;
   pArray->Capacity = Capacity;

   return 1;
}

void hbDockArrayInit(
   HB_DOCK_ARRAY * pArray )
{
   if( pArray == NULL )
      return;

   pArray->Items = NULL;
   pArray->Count = 0;
   pArray->Capacity = 0;
}

void hbDockArrayRelease(
   HB_DOCK_ARRAY * pArray )
{
   if( pArray == NULL )
      return;

   if( pArray->Items != NULL )
      free(
         pArray->Items );

   pArray->Items = NULL;
   pArray->Count = 0;
   pArray->Capacity = 0;
}

int hbDockArrayAdd(
   HB_DOCK_ARRAY * pArray,
   void * pItem )
{
   if( pArray == NULL )
      return 0;

   if( pArray->Count >= pArray->Capacity )
   {
      if( !hbDockArrayGrow(
            pArray,
            pArray->Capacity + HB_DOCK_ARRAY_GROW ) )
         return 0;
   }

   pArray->Items[ pArray->Count++ ] = pItem;

   return 1;
}

void * hbDockArrayGet(
   const HB_DOCK_ARRAY * pArray,
   int Index )
{
   if( pArray == NULL )
      return NULL;

   if( Index < 0 || Index >= pArray->Count )
      return NULL;

   return pArray->Items[ Index ];
}

int hbDockArrayRemove(
   HB_DOCK_ARRAY * pArray,
   int Index )
{
   if( pArray == NULL )
      return 0;

   if( Index < 0 || Index >= pArray->Count )
      return 0;

   if( Index < pArray->Count - 1 )
   {
      memmove(
         &pArray->Items[ Index ],
         &pArray->Items[ Index + 1 ],
         ( pArray->Count - Index - 1 ) * sizeof( void * ) );
   }

   pArray->Count--;

   return 1;
}

void hbDockArrayClear(
   HB_DOCK_ARRAY * pArray )
{
   if( pArray == NULL )
      return;

   pArray->Count = 0;
}