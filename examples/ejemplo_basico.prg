/*
 * ejemplo_basico.prg - HBDock32 v1.0
 *
 * El ejemplo minimo: dos paneles, uno a cada lado.
 *
 * Usa la clase TDockPanel (harbour_class/TDockPanel.prg) en vez del
 * comando @ PANEL de FiveWin -- ese comando tiene un desajuste de
 * parametros en su propia macro (le pasa un valor logico al
 * parametro cVarName de TPanel():New() en vez de un string) que
 * rompe la integracion con HBDock32. Confirmado con pruebas reales:
 * un control creado directo (TDockPanel, o un boton via @ BUTTON)
 * se acopla y se ve perfecto; uno creado via @ PANEL, no.
 */

#include "FiveWin.ch"
#include "hbdock.ch"

PROCEDURE Main()

   LOCAL oWnd
   LOCAL hDock
   LOCAL oExplorer, oProps

   HBDockInitialize()

   DEFINE WINDOW oWnd ;
      FROM 0, 0 TO 700, 1000 PIXEL ;
      TITLE "HBDock32 - Ejemplo basico"

   hDock := HBDockCreateManager( oWnd:hWnd )

   /* TDockPanel():New( nTop, nLeft, nBottom, nRight, oWnd, hDock, cDockName, cCaption )
    * El registro en HBDock32 (HBDockRegisterPanel) lo hace el
    * constructor solo -- no hace falta llamarlo aparte. */

   oExplorer := TDockPanel():New( 0, 0, 100, 100, oWnd, hDock, "Explorer",    "Solution Explorer" )
   oProps    := TDockPanel():New( 0, 0, 100, 100, oWnd, hDock, "Propiedades", "Propiedades" )

   oExplorer:nClrPane := RGB( 200, 220, 255 )
   oProps:nClrPane    := RGB( 255, 220, 200 )

   ACTIVATE WINDOW oWnd ;
      ON INIT ( oExplorer:Dock( HB_DOCK_LEFT ), ;
                oProps:Dock( HB_DOCK_RIGHT ) ) ;
      ON RESIZE HBDockRefreshLayout( hDock )

   HBDockDestroyManager( hDock )
   HBDockFinalize()

RETURN
