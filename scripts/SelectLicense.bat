@TITLE WebViewer 1.0
@echo off
%SystemRoot%\System32\choice.exe /C YN /N /M "The WebViewer license does not exist or has expired. Do you want to select a new license [Y/N]? "
if errorlevel 2 goto :EOF

echo So you want to select a new license. Okay, let's go ...

setlocal

set "ps_file=Add-Type -AssemblyName System.windows.forms | Out-Null;"
set "ps_file=%ps_file% $f=New-Object System.Windows.Forms.OpenFileDialog;"
set "ps_file=%ps_file% $f.Filter='Input Files (*.key)|*.key|All files (*.*)|*.*';"
set "ps_file=%ps_file% $f.showHelp=$true;"
set "ps_file=%ps_file% $f.ShowDialog() | Out-Null;"
set "ps_file=%ps_file% $f.FileName"
for /f "delims=" %%I in ('powershell "%ps_file%"') do set "filename=%%I"
if "%filename%"=="" goto nofile

echo f | xcopy /f /y "%filename%" "C:\Users\nhatv\AppData\Local\TechnoStar\WebViewer\license\hello.key"

call "C:\Users\nhatv\Work\TechnoStar\hoops-ui\Start-It.bat"

:nofile
echo ERROR : Input file not selected
goto :eof

:eof
pause
endlocal
goto :eof

:get_drive 
set "%~2=%~d1"
goto :eof

:get_path 
set "%~2=%~dp1"
goto :eof
