#include <windows.h>

#include "hbdockguidemanager.h"
#include "hbdockguidewindow.h"

#define HBDOCK_GUIDE_SIZE      32
#define HBDOCK_GUIDE_OFFSET    48

static void hbDockGuideInit(
   HB_DOCK_GUIDE * pGuide,
   HB_DOCK_GUIDE_TYPE Type )
{
   ZeroMemory(
      pGuide,
      sizeof( HB_DOCK_GUIDE ) );

   pGuide->Type = Type;

   pGuide->Visible = FALSE;

   pGuide->hWnd = NULL;

   SetRectEmpty(
      &pGuide->Rect );
}

static BOOL hbDockGuideCreateWindow(
   HB_DOCK_GUIDE * pGuide,
   HWND hParent )
{
   pGuide->hWnd =
      hbDockGuideWindowCreate(
         hParent );

   return pGuide->hWnd != NULL;
}

static void hbDockGuideDestroyWindow(
   HB_DOCK_GUIDE * pGuide )
{
   if( pGuide->hWnd != NULL )
   {
      hbDockGuideWindowDestroy(
         pGuide->hWnd );

      pGuide->hWnd = NULL;
   }
}

static void hbDockGuideShow(
   HB_DOCK_GUIDE * pGuide )
{
   pGuide->Visible = TRUE;

   hbDockGuideWindowShow(
      pGuide->hWnd );
}

static void hbDockGuideHide(
   HB_DOCK_GUIDE * pGuide )
{
   pGuide->Visible = FALSE;

   hbDockGuideWindowHide(
      pGuide->hWnd );
}

static void hbDockGuideMove(
   HB_DOCK_GUIDE * pGuide )
{
   hbDockGuideWindowMove(
      pGuide->hWnd,
      &pGuide->Rect );
}

BOOL hbDockGuideManagerCreate(
   HB_DOCK_GUIDE_MANAGER * pManager,
   HWND hParent )
{
   if( pManager == NULL )
      return FALSE;

   ZeroMemory(
      pManager,
      sizeof( HB_DOCK_GUIDE_MANAGER ) );

   pManager->hParent = hParent;

   hbDockGuideInit( &pManager->Left,   HB_GUIDE_LEFT );
   hbDockGuideInit( &pManager->Right,  HB_GUIDE_RIGHT );
   hbDockGuideInit( &pManager->Top,    HB_GUIDE_TOP );
   hbDockGuideInit( &pManager->Bottom, HB_GUIDE_BOTTOM );
   hbDockGuideInit( &pManager->Center, HB_GUIDE_CENTER );

   if( !hbDockGuideCreateWindow( &pManager->Left, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Right, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Top, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Bottom, hParent ) ||
       !hbDockGuideCreateWindow( &pManager->Center, hParent ) )
   {
      hbDockGuideManagerDestroy(
         pManager );

      return FALSE;
   }

   if( !hbDockDiamondCreate(
            &pManager->Diamond,
            hParent ) )
   {
      hbDockGuideManagerDestroy(
         pManager );

      return FALSE;
   }

   pManager->Visible = FALSE;

   return TRUE;
}

void hbDockGuideManagerDestroy(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   hbDockGuideDestroyWindow( &pManager->Left );
   hbDockGuideDestroyWindow( &pManager->Right );
   hbDockGuideDestroyWindow( &pManager->Top );
   hbDockGuideDestroyWindow( &pManager->Bottom );
   hbDockGuideDestroyWindow( &pManager->Center );

   hbDockDiamondDestroy(
      &pManager->Diamond );

   pManager->Visible = FALSE;
}

void hbDockGuideManagerShow(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   pManager->Visible = TRUE;

   hbDockGuideShow( &pManager->Left );
   hbDockGuideShow( &pManager->Right );
   hbDockGuideShow( &pManager->Top );
   hbDockGuideShow( &pManager->Bottom );
   hbDockGuideShow( &pManager->Center );

   hbDockDiamondShow(
      &pManager->Diamond );
}

void hbDockGuideManagerHide(
   HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return;

   pManager->Visible = FALSE;

   hbDockGuideHide( &pManager->Left );
   hbDockGuideHide( &pManager->Right );
   hbDockGuideHide( &pManager->Top );
   hbDockGuideHide( &pManager->Bottom );
   hbDockGuideHide( &pManager->Center );

   hbDockDiamondHide(
      &pManager->Diamond );
}

void hbDockGuideManagerMove(
   HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt )
{
   if( pManager == NULL )
      return;

   SetRect(
      &pManager->Center.Rect,
      pt.x - HBDOCK_GUIDE_SIZE / 2,
      pt.y - HBDOCK_GUIDE_SIZE / 2,
      pt.x + HBDOCK_GUIDE_SIZE / 2,
      pt.y + HBDOCK_GUIDE_SIZE / 2 );

   pManager->Left.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Left.Rect,
      -HBDOCK_GUIDE_OFFSET,
      0 );

   pManager->Right.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Right.Rect,
      HBDOCK_GUIDE_OFFSET,
      0 );

   pManager->Top.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Top.Rect,
      0,
      -HBDOCK_GUIDE_OFFSET );

   pManager->Bottom.Rect = pManager->Center.Rect;
   OffsetRect(
      &pManager->Bottom.Rect,
      0,
      HBDOCK_GUIDE_OFFSET );

   hbDockGuideMove( &pManager->Left );
   hbDockGuideMove( &pManager->Right );
   hbDockGuideMove( &pManager->Top );
   hbDockGuideMove( &pManager->Bottom );
   hbDockGuideMove( &pManager->Center );

   hbDockDiamondMove(
      &pManager->Diamond,
      pt );
}

HB_DOCK_GUIDE_TYPE hbDockGuideManagerHitTest(
   const HB_DOCK_GUIDE_MANAGER * pManager,
   POINT pt )
{
   HB_DOCK_DIAMOND_BUTTON Button;

   if( pManager == NULL )
      return HB_GUIDE_NONE;

   if( !pManager->Visible )
      return HB_GUIDE_NONE;

   Button =
      hbDockDiamondHitTest(
         &pManager->Diamond,
         pt );

   switch( Button )
   {
      case HB_DIAMOND_LEFT:   return HB_GUIDE_LEFT;
      case HB_DIAMOND_RIGHT:  return HB_GUIDE_RIGHT;
      case HB_DIAMOND_TOP:    return HB_GUIDE_TOP;
      case HB_DIAMOND_BOTTOM: return HB_GUIDE_BOTTOM;
      case HB_DIAMOND_CENTER: return HB_GUIDE_CENTER;
      default:
         break;
   }

   if( PtInRect( &pManager->Left.Rect, pt ) )
      return HB_GUIDE_LEFT;

   if( PtInRect( &pManager->Right.Rect, pt ) )
      return HB_GUIDE_RIGHT;

   if( PtInRect( &pManager->Top.Rect, pt ) )
      return HB_GUIDE_TOP;

   if( PtInRect( &pManager->Bottom.Rect, pt ) )
      return HB_GUIDE_BOTTOM;

   if( PtInRect( &pManager->Center.Rect, pt ) )
      return HB_GUIDE_CENTER;

   return HB_GUIDE_NONE;
}

BOOL hbDockGuideManagerVisible(
   const HB_DOCK_GUIDE_MANAGER * pManager )
{
   if( pManager == NULL )
      return FALSE;

   return pManager->Visible;
}