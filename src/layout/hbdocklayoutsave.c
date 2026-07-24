#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "hbdocklayoutsave.h"
#include "hbdocklayoutserialize.h"


typedef struct _HB_DOCK_LAYOUT_FILE_WRITER
{
   FILE * File;

} HB_DOCK_LAYOUT_FILE_WRITER;



static void hbDockLayoutFileWriter(
   void * Cargo,
   const char * Text )
{
   HB_DOCK_LAYOUT_FILE_WRITER * pWriter;


   pWriter =
      (HB_DOCK_LAYOUT_FILE_WRITER *) Cargo;


   if( pWriter == NULL )
      return;


   if( pWriter->File == NULL )
      return;


   if( Text == NULL )
      return;


   fputs(
      Text,
      pWriter->File );
}



BOOL hbDockLayoutSave(
   const HB_DOCK_LAYOUT_TREE * pTree,
   LPCTSTR pszFileName )
{
   FILE * File;

   HB_DOCK_LAYOUT_FILE_WRITER Writer;


   if( pTree == NULL )
      return FALSE;


   if( pszFileName == NULL )
      return FALSE;


#ifdef UNICODE

   File = _wfopen(
      pszFileName,
      L"wt" );

#else

   File = fopen(
      pszFileName,
      "wt" );

#endif


   if( File == NULL )
      return FALSE;


   Writer.File = File;


   if( !hbDockLayoutSerialize(
          pTree,
          hbDockLayoutFileWriter,
          &Writer ) )
   {
      fclose( File );
      return FALSE;
   }


   fclose( File );


   return TRUE;
}