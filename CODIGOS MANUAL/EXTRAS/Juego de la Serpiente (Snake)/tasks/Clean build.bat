@echo off

cls

cd ..

if exist build (goto clean) else (goto error)

:clean
echo Cleaning...
cd build
if exist *.o (rm *.o)
if exist *.exe (rm *.exe)
echo.
echo Clean build complete
cd ..\tasks
goto finish

:error
echo. 
echo Directory build don't exist
cd tasks

:finish
pause > nul
cls