@echo off

cls

cd ..

if exist build (cd build) else (mkdir build && cd build)

echo Actual directory
pwd
echo.

set /p filesToCompile= Insert files to compile: 

echo Building, wait please...

g++ -c -Wall -std=c++17 %filesToCompile% && g++ *.o -o app && goto buildSuccessfully

:error
if exist *.exe (rm *.exe)
echo.
echo ----------------
echo Error to compile
goto finish

:buildSuccessfully
echo.
echo ----------------
echo Build complete

:finish
cd ..\tasks
pause > nul
cls