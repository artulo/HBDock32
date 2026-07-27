/*
 * test_regresion.prg - HBDock32 v1.0
 *
 * Prueba de regresion guiada por funcionalidades (feature-driven),
 * usando la clase TDockPanel (ver examples/ejemplo_basico.prg para
 * la explicacion de por que no se usa @ PANEL de FiveWin).
 *
 * Escenario:
 *   1. Crear un panel
 *   2. Acoplarlo a la izquierda
 *   3. "Arrastrarlo" al centro
 *   4. Convertirlo en pestana
 *   5. Pasarlo a AutoHide
 *   6. Restaurarlo de AutoHide
 *   7. Hacerlo flotante
 *   8. Guardar el layout
 *   9. Restaurar el layout
 *
 * Resultado: PASS/FAIL por paso en pantalla y en test_regresion.log
 */

#include "FiveWin.ch"
#include "hbdock.ch"

STATIC nChecks := 0
STATIC nFailed := 0

PROCEDURE Main()

   LOCAL oWnd
   LOCAL hDock
   LOCAL oPanelA, oPanelB
   LOCAL cLayoutFile := "test_layout.tmp"
   LOCAL hLog := FCreate( "test_regresion.log" )

   ? "HBDock32 v1.0 - Prueba de regresion"
   ? "===================================="
   ?

   Check( hLog, HBDockInitialize(), "HBDockInitialize()" )

   DEFINE WINDOW oWnd ;
      FROM 0, 0 TO 600, 900 PIXEL ;
      TITLE "Test de regresion HBDock32"

   hDock := HBDockCreateManager( oWnd:hWnd )
   Check( hLog, hDock != NIL .AND. hDock != 0, "HBDockCreateManager()" )

   /* El constructor de TDockPanel ya registra el panel en HBDock32 --
    * si el manager/registro fallara, oPanelA/oPanelB igual quedan
    * creados como controles FiveWin normales (con HBDockRegisterPanel
    * devolviendo .F. adentro), asi que igual verificamos aparte. */

   oPanelA := TDockPanel():New( 0, 0, 100, 100, oWnd, hDock, "PanelA", "Panel A" )
   oPanelB := TDockPanel():New( 0, 0, 100, 100, oWnd, hDock, "PanelB", "Panel B" )

   Check( hLog, !Empty( oPanelA:hWnd ), "1. Crear Panel A" )
   Check( hLog, !Empty( oPanelB:hWnd ), "1. Crear Panel B" )

   /* --- 2. Acoplarlo a la izquierda --- */
   Check( hLog, oPanelA:Dock( HB_DOCK_LEFT ), "2. Acoplar Panel A a la izquierda" )

   /* --- 3. "Arrastrarlo" al centro --- */
   Check( hLog, oPanelB:Dock( HB_DOCK_CENTER ), "3. Arrastrar Panel B al centro" )

   /* --- 4. Convertirlo en pestana explicitamente --- */
   Check( hLog, oPanelB:TabifyOn( "PanelA" ), "4. Tabificar Panel B sobre Panel A" )

   /* --- 5. Pasarlo a AutoHide --- */
   Check( hLog, oPanelA:AutoHide(), "5. AutoHide de Panel A" )

   /* --- 6. Restaurarlo de AutoHide --- */
   Check( hLog, oPanelA:RestoreAutoHide(), "6. Restaurar Panel A de AutoHide" )

   /* --- 7. Hacerlo flotante --- */
   Check( hLog, oPanelB:Float(), "7. Flotar Panel B" )

   /* --- 8. Guardar el layout --- */
   Check( hLog, HBDockSaveWorkspace( hDock, cLayoutFile ), "8. Guardar layout" )
   Check( hLog, File( cLayoutFile ), "8b. El archivo de layout se creo en disco" )

   /* --- 9. Restaurar el layout --- */
   Check( hLog, HBDockLoadWorkspace( hDock, cLayoutFile ), "9. Restaurar layout" )

   /* --- Limpieza --- */
   HBDockDestroyManager( hDock )
   HBDockFinalize()

   oWnd:End()

   IF File( cLayoutFile )
      FErase( cLayoutFile )
   ENDIF

   ?
   ? "===================================="
   ? "Total de verificaciones: " + hb_ntos( nChecks )
   ? "Fallidas:                " + hb_ntos( nFailed )

   IF nFailed == 0
      ? "RESULTADO: TODO OK"
   ELSE
      ? "RESULTADO: HAY FALLAS -- revisa test_regresion.log"
   ENDIF

   FClose( hLog )

RETURN

STATIC PROCEDURE Check( hLog, lCond, cDesc )

   LOCAL cLine

   nChecks++

   IF lCond
      cLine := "[PASS] " + cDesc
   ELSE
      cLine := "[FAIL] " + cDesc
      nFailed++
   ENDIF

   ? cLine

   FWrite( hLog, cLine + hb_eol() )

RETURN
