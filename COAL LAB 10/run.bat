@echo off
rem ml.exe /I"C:\Users\Raedo\Documents\dev\compilers\irvine" ..\learning.asm /link /LIBPATH:"C:\Users\Raedo\Documents\dev\compilers\irvine" /SUBSYSTEM:CONSOLE Irvine32.lib kernel32.lib user32.lib
 ml.exe /I"C:\Users\Raedo\Documents\dev\compilers\irvine" ..\q3.asm /link /LIBPATH:"C:\Users\Raedo\Documents\dev\compilers\irvine" /SUBSYSTEM:CONSOLE Irvine32.lib kernel32.lib user32.lib
rem ml.exe /I"C:\Users\Raedo\Documents\dev\compilers\irvine" ..\q2.asm /link /LIBPATH:"C:\Users\Raedo\Documents\dev\compilers\irvine" /SUBSYSTEM:CONSOLE Irvine32.lib kernel32.lib user32.lib