/*
 * ejemplo_tdockpanel.prg - HBDock32 v1.0
 *
 * Prueba usando la clase TDockPanel en vez de TPanel + llamadas
 * sueltas. Como se llama a TDockPanel():New() directo (no a traves
 * de la macro @ PANEL de FiveWin), tambien evita el desajuste de
 * parametros de esa macro para el borde -- estos paneles deberian
 * verse con borde real.
 */

#include "FiveWin.ch"
#include "hbdock.ch"

PROCEDURE Main()

   LOCAL oWnd
   LOCAL hDock
   LOCAL oExplorer, oProps, oOutput

   HBDockInitialize()

   DEFINE WINDOW oWnd ;
      FROM 0, 0 TO 770, 1200 PIXEL ;
      TITLE "HBDock32 - Prueba con TDockPanel"

   hDock := HBDockCreateManager( oWnd:hWnd )

   /* TDockPanel():New( nTop, nLeft, nBottom, nRight, oWnd, hDock, cDockName, cCaption )
    * El registro en HBDock32 ya lo hace el constructor -- no hace
    * falta llamar a HBDockRegisterPanel() aparte. */

   oExplorer := TDockPanel():New( 30, 0, 60, 25, oWnd, hDock, "Explorer", "Explorador" )
   oProps    := TDockPanel():New( 30, 25, 60, 50, oWnd, hDock, "Propiedades", "Propiedades" )
   oOutput   := TDockPanel():New( 60, 0, 70, 25, oWnd, hDock, "Salida", "Salida" )

   oExplorer:nClrPane := RGB( 200, 220, 255 )
   oProps:nClrPane    := RGB( 255, 220, 200 )
   oOutput:nClrPane   := RGB( 210, 255, 210 )

   ACTIVATE WINDOW oWnd ;
      ON INIT ( oExplorer:Dock( HB_DOCK_LEFT ), ;
                oOutput:Dock( HB_DOCK_BOTTOM ), ;
                MsgInfo( "Explorer: " + hb_ValToExp( GETWNDRECT( oExplorer:hWnd ) ) + hb_eol() + ;
                         "Salida:   " + hb_ValToExp( GETWNDRECT( oOutput:hWnd ) ) ) ) ;
      ON RESIZE HBDockRefreshLayout( hDock )

   HBDockDestroyManager( hDock )
   HBDockFinalize()

RETURN
