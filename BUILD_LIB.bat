@echo off
setlocal enabledelayedexpansion

REM ============================================================
REM  HBDock32 v1.0 - Genera la biblioteca estatica HBDOCK32.LIB
REM
REM  Compila TODO el proyecto (nucleo C + puente Harbour) y arma
REM  una sola biblioteca .LIB con tlib (el librarian de Borland),
REM  lista para linkear directo en cualquier .exe de FiveWin/Harbour
REM  junto con fwh32.lib y las librerias de Harbour.
REM
REM  Requiere: BCC (Embarcadero) y el SDK de Harbour de tu FWH.
REM  Ajusta las rutas de abajo si no coinciden con tu maquina.
REM ============================================================

set BCCDIR=D:\prgsmio\bcc73
set BCC32=%BCCDIR%\bin\bcc32.exe
set TLIB=%BCCDIR%\bin\tlib.exe
set BCCINC=%BCCDIR%\include

set HBDIR=D:\prgsmio\FWH2603\harbour
set HBINC=%HBDIR%\include

if not exist "%BCC32%" (
    echo ERROR: no se encuentra "%BCC32%"
    pause
    goto :EOF
)

if not exist "%TLIB%" (
    echo ERROR: no se encuentra "%TLIB%" ^(el librarian de Borland^)
    echo Deberia estar junto a bcc32.exe en %BCCDIR%\bin
    pause
    goto :EOF
)

set PROJDIR=%~dp0
set OBJDIR=%PROJDIR%obj_lib
set OUTDIR=%PROJDIR%lib
set LOGFILE=%PROJDIR%BUILD_LIB_LOG.txt
set LIBNAME=%OUTDIR%\HBDOCK32.LIB

if not exist "%OBJDIR%" mkdir "%OBJDIR%"
if not exist "%OUTDIR%" mkdir "%OUTDIR%"

REM Limpieza de objetos de una corrida anterior -- si borramos algun
REM .c en una vuelta de correccion anterior, su .obj viejo podria
REM seguir en esta carpeta y colarse en la biblioteca. Se arranca
REM siempre de cero.
if exist "%OBJDIR%\*.obj" del /Q "%OBJDIR%\*.obj"

if exist "%LIBNAME%" del /Q "%LIBNAME%"
if exist "%LOGFILE%" del /Q "%LOGFILE%"

echo HBDock32 v1.0 - log de generacion de biblioteca > "%LOGFILE%"
echo Fecha: %DATE% %TIME% >> "%LOGFILE%"
echo. >> "%LOGFILE%"

set /A TOTAL=0
set /A ERRORS=0

echo.
echo === Paso 1/2: compilando nucleo C + puente Harbour ===
echo.

for /R "%PROJDIR%src" %%f in (*.c) do (
    set /A TOTAL+=1

    echo Compilando: %%~nxf
    echo ---------------------------------------------- >> "%LOGFILE%"
    echo %%f >> "%LOGFILE%"

    "%BCC32%" -c -q -O2 -I"%PROJDIR%include";"%BCCINC%";"%HBINC%" -n"%OBJDIR%" "%%f" >> "%LOGFILE%" 2>&1

    if errorlevel 1 (
        echo   *** ERROR ***
        set /A ERRORS+=1
    )
)

echo.
echo Archivos procesados: %TOTAL%  -  Con error: %ERRORS%
echo.

if %ERRORS% GTR 0 (
    echo Hay errores de compilacion -- revisa %LOGFILE% antes de
    echo intentar armar la biblioteca. Pegale ese log a Claude.
    pause
    goto :EOF
)

echo === Paso 2/2: armando %LIBNAME% con tlib ===
echo.

REM Nota de estabilizacion: se probaron 2 metodos antes de este.
REM   1) Un archivo de respuesta con las 439 rutas y una sola
REM      invocacion de tlib con @respuesta.rsp -- se corto despues
REM      de agregar un solo objeto, sin error.
REM   2) Una invocacion de tlib por cada .obj (439 invocaciones) --
REM      tambien termino con un solo objeto en la biblioteca.
REM
REM Se usa ahora el metodo mas robusto conocido para tlib: agrupar
REM varios "+objeto" en una misma linea de comando, en lotes chicos
REM (para no pasarse del limite de longitud de linea de CMD.EXE), y
REM hacer pocas invocaciones en vez de 439 o 1.

set /A LIBCOUNT=0
set /A BATCHSIZE=0
set BATCHOPS=

for %%o in ("%OBJDIR%\*.obj") do (
    set /A LIBCOUNT+=1
    set /A BATCHSIZE+=1
    set BATCHOPS=!BATCHOPS! +"%%o"

    if !BATCHSIZE! GEQ 30 (
        "%TLIB%" "%LIBNAME%" /C !BATCHOPS! >> "%LOGFILE%" 2>&1
        set BATCHOPS=
        set /A BATCHSIZE=0
    )
)

REM Ultimo lote incompleto, si quedo algo pendiente.
if not "!BATCHOPS!" == "" (
    "%TLIB%" "%LIBNAME%" /C !BATCHOPS! >> "%LOGFILE%" 2>&1
)

echo Objetos procesados: %LIBCOUNT%
echo Objetos procesados: %LIBCOUNT% >> "%LOGFILE%"

if not exist "%LIBNAME%" (
    echo *** ERROR: tlib no genero %LIBNAME% -- revisa %LOGFILE% ***
    pause
    goto :EOF
)

for %%s in ("%LIBNAME%") do (
    echo Tamano de %LIBNAME%: %%~zs bytes
    echo Tamano de %LIBNAME%: %%~zs bytes >> "%LOGFILE%"

    if %%~zs LSS 100000 (
        echo.
        echo *** ATENCION: el archivo pesa muy poco para 439 objetos
        echo     adentro -- probablemente solo se agregaron unos
        echo     pocos. Pegale este log a Claude antes de usar el .lib.
        echo.
    )
)

echo.
echo ================================================
echo  Listo: %LIBNAME%
echo ================================================
echo.
echo  Para usarla en tu proyecto FiveWin/Harbour, agregala a la
echo  lista de librerias de tu script de enlazado junto con
echo  fwh32.lib y las librerias de Harbour (hbvm.lib, hbrtl.lib,
echo  hblang.lib, hbcommon.lib, gtwin.lib -- los nombres exactos
echo  segun tu instalacion de FWH2603).
echo.

pause
