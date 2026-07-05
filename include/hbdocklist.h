#ifndef HBDOCKLIST_H
#define HBDOCKLIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _HB_DOCK_NODE
{
   void * Data;

   struct _HB_DOCK_NODE * Next;
   struct _HB_DOCK_NODE * Prev;

} HB_DOCK_NODE;

typedef struct
{
   HB_DOCK_NODE * First;
   HB_DOCK_NODE * Last;

   unsigned Count;

} HB_DOCK_LIST;

void hbDockListInit(
   HB_DOCK_LIST * pList );

HB_DOCK_NODE * hbDockListAppend(
   HB_DOCK_LIST * pList,
   void * Data );

HB_DOCK_NODE * hbDockListPrepend(
   HB_DOCK_LIST * pList,
   void * Data );

void hbDockListRemove(
   HB_DOCK_LIST * pList,
   HB_DOCK_NODE * pNode );

void hbDockListClear(
   HB_DOCK_LIST * pList );

#ifdef __cplusplus
}
#endif

#endif