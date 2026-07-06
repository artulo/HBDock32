#include "hbdocktheme.h"

void hbDockThemeDefault(
   HB_DOCK_THEME * pTheme )
{
   if( pTheme == NULL )
      return;

   pTheme->Background = RGB(240,240,240);
   pTheme->Border = RGB(140,140,140);
   pTheme->Caption = RGB(0,122,204);
   pTheme->CaptionText = RGB(255,255,255);
   pTheme->TabActive = RGB(255,255,255);
   pTheme->TabInactive = RGB(220,220,220);
   pTheme->Guide = RGB(0,120,215);
}