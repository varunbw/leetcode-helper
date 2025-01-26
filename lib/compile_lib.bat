@echo off
setlocal enabledelayedexpansion

:: Remove the library file if it exists
del /f /q liblch.a 2>nul

:: Array of filenames without paths
set "FILES=misc binary_tree graph linked_list args_parser stream_parser perf"

set "LIBRARY_NAME=liblch.a"

:: Construct a string of source file paths
set "SOURCE_FILES="
for %%F in (%FILES%) do (
    set "SOURCE_FILES=!SOURCE_FILES! ../src/%%F.cpp"
)

:: Compile into object files in one g++ call
g++ -g -c -std=c++17 %SOURCE_FILES%
if errorlevel 1 (
    echo Compilation failed
    exit /b 1
)

:: Create a list of object files
set "OBJECT_FILES="
for %%F in (%FILES%) do (
    set "OBJECT_FILES=!OBJECT_FILES! %%F.o"
)

:: Make the library file
ar rcs %LIBRARY_NAME% %OBJECT_FILES%
if errorlevel 1 (
    echo Archival failed
    exit /b 1
)

:: Delete object files
for %%F in (%FILES%) do (
    del /f /q %%F.o
)

if not errorlevel 1 (
    echo Library successfully made
)
