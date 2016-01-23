@echo off

echo Preparing run

echo - Copying libs
xcopy /I /Y SFML-Windows-VS\bin A-Maz-Ing\x64\Debug

echo - Copying images
xcopy /I /Y images A-Maz-Ing\x64\Debug\images

echo - Copying patterns
xcopy /I /Y Patterns A-Maz-Ing\x64\Debug\Patterns

echo Run!
A-Maz-Ing\x64\Debug\A-Maz-Ing.exe

echo Press a key to close...
pause > nul