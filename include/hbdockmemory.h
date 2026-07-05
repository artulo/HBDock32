#ifndef HBDOCKMEMORY_H
#define HBDOCKMEMORY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void * hbDockAlloc(
   size_t Size );

void * hbDockCalloc(
   size_t Count,
   size_t Size );

void hbDockFree(
   void * pMemory );

#ifdef __cplusplus
}
#endif

#endif