#include <string.h>

#include "hbdockarray.h"

extern int hbDockArrayResize(
   HB_DOCK_ARRAY * pArray,
   int NewCapacity );

int hbDockArrayInsert(
   HB_DOCK_ARRAY * pArray,
   int Index,
   void * pItem )
{
   int i;

   if( pArray == NULL )
      return 0;

   if( Index < 0 )
      Index = 0;

   if( Index > pArray->Count )
      Index = pArray->Count;

   if( !hbDockArrayResize(
            pArray,
            pArray->Count + 1 ) )
      return 0;

   for( i = pArray->Count - 1;
        i > Index;
        --i )
   {
      pArray->Items[ i ] =
         pArray->Items[ i - 1 ];
   }

   pArray->Items[ Index ] = pItem;

   return 1;
}