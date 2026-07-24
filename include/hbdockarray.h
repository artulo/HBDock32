#ifndef HBDOCKARRAY_H
#define HBDOCKARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_ARRAY
{
   void ** Items;
   int Count;
   int Capacity;

} HB_DOCK_ARRAY;


void hbDockArrayInit(
   HB_DOCK_ARRAY * pArray );


void hbDockArrayDestroy(
   HB_DOCK_ARRAY * pArray );


int hbDockArrayAdd(
   HB_DOCK_ARRAY * pArray,
   void * pItem );


void * hbDockArrayGet(
   HB_DOCK_ARRAY * pArray,
   int Index );


int hbDockArrayRemove(
   HB_DOCK_ARRAY * pArray,
   int Index );


void hbDockArrayClear(
   HB_DOCK_ARRAY * pArray );


#ifdef __cplusplus
}
#endif

#endif