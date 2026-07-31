#include "hbdocktheme.h"

/*
 * Etapa 82: pedido explicito -- el mapeo estaba al reves. El
 * gradiente "normal" (mas sutil -- celeste en 2007, blanco/gris en
 * 2010, gris en 2015) va al CAPTION; el "inverted" (mas resaltado --
 * dorado en 2007, azul brillante en 2010/2015) va a las pestañas
 * INACTIVAS. Paleta real de Gradient2000 (FiveWin), sin cambios en
 * los VALORES de color -- solo se invirtio a cual elemento va cada
 * gradiente.
 */

static HB_DOCK_THEME_ID s_CurrentThemeId = HBDOCK_THEME_OFFICE2007;
static HB_DOCK_THEME s_CurrentTheme;
static int s_Initialized = 0;

void hbDockThemeDefault(
   HB_DOCK_THEME * pTheme )
{
   hbDockThemeGetById(
      HBDOCK_THEME_OFFICE2007,
      pTheme );
}

void hbDockThemeGetById(
   HB_DOCK_THEME_ID ThemeId,
   HB_DOCK_THEME * pTheme )
{
   if( pTheme == NULL )
      return;

   switch( ThemeId )
   {
      case HBDOCK_THEME_OFFICE2010:

         /*
          * Office 2010 (Gradient2000 nAt==2). Caption: blanco a gris
          * clarito, un solo tramo (gradiente "normal"). Pestaña
          * inactiva: azul "glossy" de 2 tramos (gradiente
          * "inverted").
          */
         pTheme->CaptionGrad.Fraction1 = 1.0f;
         pTheme->CaptionGrad.Top1    = RGB( 255, 255, 255 );
         pTheme->CaptionGrad.Bottom1 = RGB( 229, 233, 238 );
         pTheme->CaptionGrad.Top2    = pTheme->CaptionGrad.Top1;
         pTheme->CaptionGrad.Bottom2 = pTheme->CaptionGrad.Bottom1;

         pTheme->TabInactiveGrad.Fraction1 = 0.5f;
         pTheme->TabInactiveGrad.Top1    = RGB( 242, 244, 246 );
         pTheme->TabInactiveGrad.Bottom1 = RGB( 145, 201, 247 );
         pTheme->TabInactiveGrad.Top2    = RGB( 145, 201, 247 );
         pTheme->TabInactiveGrad.Bottom2 = RGB( 242, 244, 246 );

         pTheme->Background      = RGB( 245, 246, 247 );
         pTheme->Border          = RGB( 180, 180, 190 );
         pTheme->Caption         = pTheme->CaptionGrad.Top1;
         pTheme->CaptionBottom   = pTheme->CaptionGrad.Bottom1;
         pTheme->CaptionText     = RGB( 30, 30, 30 );
         pTheme->TabActive       = pTheme->CaptionGrad.Top1;
         pTheme->TabInactive     = pTheme->TabInactiveGrad.Top1;
         pTheme->TabInactiveText = RGB( 20, 30, 50 );
         pTheme->Guide           = RGB( 145, 201, 247 );
         pTheme->SplitterBg      = RGB( 200, 203, 207 );
         pTheme->TabSeparator    = RGB( 200, 203, 207 );
         break;

      case HBDOCK_THEME_OFFICE2015:

         /*
          * Office 2015 (Gradient2000 nAt==4). Caption: gris plano
          * (gradiente "normal"). Pestaña inactiva: azul plano
          * (gradiente "inverted"). Sin degradado real (Fraction1=1).
          */
         pTheme->CaptionGrad.Fraction1 = 1.0f;
         pTheme->CaptionGrad.Top1    = RGB( 244, 244, 245 );
         pTheme->CaptionGrad.Bottom1 = RGB( 244, 244, 245 );
         pTheme->CaptionGrad.Top2    = pTheme->CaptionGrad.Top1;
         pTheme->CaptionGrad.Bottom2 = pTheme->CaptionGrad.Bottom1;

         pTheme->TabInactiveGrad.Fraction1 = 1.0f;
         pTheme->TabInactiveGrad.Top1    = RGB( 145, 201, 247 );
         pTheme->TabInactiveGrad.Bottom1 = RGB( 145, 201, 247 );
         pTheme->TabInactiveGrad.Top2    = pTheme->TabInactiveGrad.Top1;
         pTheme->TabInactiveGrad.Bottom2 = pTheme->TabInactiveGrad.Bottom1;

         pTheme->Background      = RGB( 244, 244, 245 );
         pTheme->Border          = RGB( 145, 201, 247 );
         pTheme->Caption         = pTheme->CaptionGrad.Top1;
         pTheme->CaptionBottom   = pTheme->CaptionGrad.Bottom1;
         pTheme->CaptionText     = RGB( 20, 20, 20 );
         pTheme->TabActive       = pTheme->CaptionGrad.Top1;
         pTheme->TabInactive     = pTheme->TabInactiveGrad.Top1;
         pTheme->TabInactiveText = RGB( 20, 20, 20 );
         pTheme->Guide           = RGB( 145, 201, 247 );
         pTheme->SplitterBg      = RGB( 210, 210, 210 );
         pTheme->TabSeparator    = RGB( 210, 210, 210 );
         break;

      case HBDOCK_THEME_OFFICE2007:
      default:

         /*
          * Office 2007 (Gradient2000 nAt==1). Caption: celeste de 2
          * tramos (gradiente "normal"). Pestaña inactiva: amarillo/
          * dorado de 2 tramos (gradiente "inverted", el clasico
          * resaltado Office 2007).
          */
         pTheme->CaptionGrad.Fraction1 = 0.25f;
         pTheme->CaptionGrad.Top1    = RGB( 219, 230, 244 );
         pTheme->CaptionGrad.Bottom1 = RGB( 207, 221, 239 );
         pTheme->CaptionGrad.Top2    = RGB( 201, 217, 237 );
         pTheme->CaptionGrad.Bottom2 = RGB( 231, 242, 255 );

         pTheme->TabInactiveGrad.Fraction1 = 0.25f;
         pTheme->TabInactiveGrad.Top1    = RGB( 255, 253, 222 );
         pTheme->TabInactiveGrad.Bottom1 = RGB( 255, 231, 151 );
         pTheme->TabInactiveGrad.Top2    = RGB( 255, 215, 84 );
         pTheme->TabInactiveGrad.Bottom2 = RGB( 255, 233, 162 );

         pTheme->Background      = RGB( 233, 236, 242 );
         pTheme->Border          = RGB( 180, 195, 220 );
         pTheme->Caption         = pTheme->CaptionGrad.Top1;
         pTheme->CaptionBottom   = pTheme->CaptionGrad.Bottom2;
         pTheme->CaptionText     = RGB( 20, 30, 50 );
         pTheme->TabActive       = pTheme->CaptionGrad.Top1;
         pTheme->TabInactive     = pTheme->TabInactiveGrad.Top1;
         pTheme->TabInactiveText = RGB( 40, 30, 0 );
         pTheme->Guide           = RGB( 21, 66, 139 );
         pTheme->SplitterBg      = RGB( 160, 175, 200 );
         pTheme->TabSeparator    = RGB( 160, 175, 200 );
         break;
   }
}

void hbDockThemeSetCurrent(
   HB_DOCK_THEME_ID ThemeId )
{
   s_CurrentThemeId = ThemeId;

   hbDockThemeGetById(
      ThemeId,
      &s_CurrentTheme );

   s_Initialized = 1;
}

HB_DOCK_THEME_ID hbDockThemeGetCurrentId( void )
{
   return s_CurrentThemeId;
}

const HB_DOCK_THEME * hbDockThemeGetCurrent( void )
{
   if( !s_Initialized )
      hbDockThemeSetCurrent(
         HBDOCK_THEME_OFFICE2007 );

   return &s_CurrentTheme;
}
