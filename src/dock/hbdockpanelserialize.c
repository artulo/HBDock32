#include <stdio.h>
#include <string.h>

#include "hbdockpanelserialize.h"

int hbDockPanelSave(
   FILE * fp,
   const HB_DOCK_PANEL * pPanel )
{
   if( fp == NULL || pPanel == NULL )
      return 0;

   fprintf(
      fp,
      "%u\n",
      pPanel->Id );

   fprintf(
      fp,
      "%s\n",
      pPanel->Name );

   fprintf(
      fp,
      "%s\n",
      pPanel->Caption );

   fprintf(
      fp,
      "%lu\n",
      pPanel->Options );

   return 1;
}

int hbDockPanelLoad(
   FILE * fp,
   HB_DOCK_PANEL * pPanel )
{
   if( fp == NULL || pPanel == NULL )
      return 0;

   fscanf(
      fp,
      "%u\n",
      &pPanel->Id );

   fgets(
      pPanel->Name,
      sizeof( pPanel->Name ),
      fp );

   pPanel->Name[
      strcspn(
         pPanel->Name,
         "\r\n" ) ] = 0;

   fgets(
      pPanel->Caption,
      sizeof( pPanel->Caption ),
      fp );

   pPanel->Caption[
      strcspn(
         pPanel->Caption,
         "\r\n" ) ] = 0;

   fscanf(
      fp,
      "%lu",
      &pPanel->Options );

   return 1;
}