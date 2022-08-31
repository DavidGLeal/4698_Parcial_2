@echo off

cls

cd ..

if exist build (cd build) else (mkdir build && cd build)

echo Building, wait please...

g++ -c -Wall -std=c++17 ..\source\*.cpp && g++ *.o -o app && goto buildSuccesfully

:error
if exist *.exe (rm *.exe)
if exist *.o (rm *.o)
echo.
echo ------------------------
echo Error to compile
goto finish

:buildSuccesfully
echo.
echo ------------------------
echo Build complete

:finish
cd ..\tasks
pause > nul
cls