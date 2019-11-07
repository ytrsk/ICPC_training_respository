@echo off
:loop
	test > test.in
	my.exe < test.in > my.out
	std.exe < test.in > std.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop
