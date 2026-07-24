#include "hbdocklayoutload.h"

#include "hbdocklayoutdeserialize.h"


typedef struct _HB_DOCK_LAYOUT_BUFFER_READER
{
   const char * Text;

} HB_DOCK_LAYOUT_BUFFER_READER;



static const char * hbDockLayoutBufferReader(
   void * Cargo )
{
   HB_DOCK_LAYOUT_BUFFER_READER * pReader;


   pReader =
      (HB_DOCK_LAYOUT_BUFFER_READER *) Cargo;


   if( pReader == NULL )
      return NULL;


   return pReader->Text;
}



BOOL hbDockLayoutLoad(
   HB_DOCK_LAYOUT_TREE * pTree,
   const char * Text )
{
   HB_DOCK_LAYOUT_BUFFER_READER Reader;


   if( pTree == NULL )
      return FALSE;


   if( Text == NULL )
      return FALSE;


   Reader.Text = Text;


   return hbDockLayoutDeserialize(
      pTree,
      hbDockLayoutBufferReader,
      &Reader );
}