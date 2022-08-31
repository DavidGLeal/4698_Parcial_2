@echo off

cls

cd ..

if exist build (
	cd build
	goto runProgram
) else (
	goto error
)

:runProgram
if exist app.exe (
	.\app.exe
	echo.
	echo --------------------------------
	echo Program finish with return value %ERRORLEVEL%
	cd ..
	goto finish
) else (
	cd ..
	goto error
)

:error
echo.
echo --------------------------------
echo Executable program (app.exe) or directory (build) not found

:finish
cd tasks
pause > nul
cls