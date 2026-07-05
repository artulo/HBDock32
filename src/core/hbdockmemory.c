#include <stdlib.h>

#include "hbdockmemory.h"

void * hbDockAlloc(
   size_t Size )
{
   return malloc(
      Size );
}

void * hbDockCalloc(
   size_t Count,
   size_t Size )
{
   return calloc(
      Count,
      Size );
}

void hbDockFree(
   void * pMemory )
{
   if( pMemory != NULL )
      free(
         pMemory );
}