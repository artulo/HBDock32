/*
 * ejemplo_test_boton.prg - HBDock32 v1.0
 *
 * Prueba rapida de aislamiento: en vez de acoplar un TPanel,
 * acoplamos un boton comun (que ya confirmamos que se ve bien) para
 * saber si el problema es especifico de TPanel o afecta a cualquier
 * ventana movida por HBDock32 desde afuera de FiveWin.
 */

#include "FiveWin.ch"
#include "hbdock.ch"

PROCEDURE Main()

   LOCAL oWnd
   LOCAL hDock
   LOCAL oBtn

   HBDockInitialize()

   DEFINE WINDOW oWnd ;
      FROM 0, 0 TO 600, 900 PIXEL ;
      TITLE "HBDock32 - Test de aislamiento (boton)"

   @ 5, 5 BUTTON oBtn PROMPT "Soy un boton" SIZE 20, 3 OF oWnd

   hDock := HBDockCreateManager( oWnd:hWnd )

   HBDockRegisterPanel( hDock, oBtn:hWnd, "Boton", "Boton de prueba" )

   ACTIVATE WINDOW oWnd ;
      ON INIT ( MsgInfo( "Dock -> " + iif( HBDockPanel( hDock, "Boton", HB_DOCK_LEFT ), "TRUE", "FALSE" ) ), ;
                MsgInfo( "Rect real del boton: " + hb_ValToExp( GETWNDRECT( oBtn:hWnd ) ) ) ) ;
      ON RESIZE HBDockRefreshLayout( hDock )

   HBDockDestroyManager( hDock )
   HBDockFinalize()

RETURN
