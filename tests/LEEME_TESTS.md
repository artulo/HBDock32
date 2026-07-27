# HBDock32 v1.0 — Prueba de regresión

## Qué hace `test_regresion.prg`

Ejecuta, en secuencia y contra una ventana real (2 paneles), el escenario completo pedido para v1.0:

1. Crear/registrar 2 paneles
2. Acoplar Panel A a la izquierda
3. "Arrastrar" Panel B al centro (vía `HBDockPanel(..., HB_DOCK_CENTER)` — la misma llamada que usa internamente el árbol de docking cuando el usuario suelta sobre la guía central)
4. Tabificar explícitamente por nombre (`HBDockTabifyPanel`)
5. AutoHide de Panel A
6. Restaurar de AutoHide
7. Flotar Panel B
8. Guardar el layout a disco
9. Restaurar el layout desde disco

Cada paso se imprime en pantalla como `[PASS]`/`[FAIL]` y queda registrado en `test_regresion.log`. Al final, un resumen con el total de verificaciones y cuántas fallaron.

## Qué NO verifica (limitación honesta)

La API pública actual (15 funciones, ver `doc/API.md`) **no expone ninguna función de introspección** — no hay forma de preguntarle a HBDock32 desde Harbour "¿en qué sitio está este panel ahora?" o "¿está flotando?". Por eso, cada paso de esta prueba solo puede verificar **que la llamada devolvió `.T.`** (que la operación se ejecutó sin rechazarse), no que el resultado geométrico/visual sea el esperado.

Es una prueba de regresión real y útil — detecta si algo se rompe a nivel de "la función ahora falla cuando antes no fallaba" — pero no reemplaza una inspección visual manual para confirmar que el panel efectivamente *se ve* donde debería.

## Cómo extenderla

Si en una v1.1 se agregan getters de estado (por ejemplo `HBDockPanelGetSite()`, `HBDockPanelIsFloating()`, `HBDockPanelGetRect()`), este mismo test se puede profundizar agregando verificaciones de geometría/estado real después de cada paso, en vez de solo el valor de retorno.

## Cómo correrla

Compilala junto con `HBDOCK32.LIB` (mismo procedimiento que cualquier ejemplo, ver `doc/GUIA_DE_USO.md`) y ejecutá el `.exe` resultante. La ventana de prueba se abre y se cierra sola; el resultado queda en la consola y en `test_regresion.log`.
