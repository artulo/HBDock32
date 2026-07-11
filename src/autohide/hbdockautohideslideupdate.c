#include "hbdockautohideslideupdate.h"
#include "hbdockautohideslideanimation.h"
#include "hbdockautohideslidelimits.h"
#include "hbdockautohideslideapply.h"
#include "hbdockautohideslidefinished.h"
#include "hbdockautohideslideengine.h"

void hbDockAutoHideUpdateSlide(
   HB_DOCK_AUTOHIDE_PANE * pPane )
{
   if( pPane == NULL )
      return;

   if( !pPane->Sliding )
      return;

   hbDockAutoHideAnimationStep( pPane );

   hbDockAutoHideNormalizeSlide( pPane );

   hbDockAutoHideApplySlide( pPane );

   if( hbDockAutoHideSlideFinished( pPane ) )
      hbDockAutoHideStopSlide( pPane );
}