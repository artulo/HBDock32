#include "hbdockautohideslideupdate.h"

#include "hbdockautohideslideanimation.h"
#include "hbdockautohideslidelimits.h"
#include "hbdockautohideslideapply.h"
#include "hbdockautohideslidefinished.h"
#include "hbdockautohideslideengine.h"


void hbDockAutoHideUpdateSlide(
   HB_DOCK_AUTOHIDE * pAutoHide )
{
   if( pAutoHide == NULL )
      return;

   if( !pAutoHide->Sliding )
      return;


   hbDockAutoHideAnimationStep(
      pAutoHide );


   hbDockAutoHideNormalizeSlide(
      pAutoHide );


   hbDockAutoHideApplySlide(
      pAutoHide );


   if( hbDockAutoHideSlideFinished(
          pAutoHide ) )
   {
      hbDockAutoHideStopSlide(
         pAutoHide );
   }
}