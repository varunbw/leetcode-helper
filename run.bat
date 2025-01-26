@echo off
setlocal enabledelayedexpansion

set "SOURCE_FILE=main.cpp"
set "OUTPUT_FILE=main.exe"
set "LIBRARY_FILE=lch"

:: Base compile command
set "COMPILE_CMD=g++ -g %SOURCE_FILE% -o %OUTPUT_FILE% -Llib -l%LIBRARY_FILE% -std=c++17"

:: Compile the source file
echo Compiling with command: %COMPILE_CMD%
%COMPILE_CMD%

:: Check if compilation was successful
if errorlevel 1 (
    echo Compilation failed
    exit /b 1
)

echo Compilation successful
echo -----------------------------------------------------------------------------------------
:: Run the compiled output
%OUTPUT_FILE% %*
