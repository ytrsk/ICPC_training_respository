@echo off
set xv_path=D:\\StudyAndWork\\VIVADO\\VIVADO\\Vivado\\2015.2\\bin
call %xv_path%/xelab  -wto 8b7bd2e99a974e8baa6556427e2201a6 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot s_behav xil_defaultlib.s xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
