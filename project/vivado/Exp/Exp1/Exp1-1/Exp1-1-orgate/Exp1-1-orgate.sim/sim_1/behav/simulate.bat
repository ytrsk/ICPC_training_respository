@echo off
set xv_path=D:\\StudyAndWork\\VIVADO\\VIVADO\\Vivado\\2015.2\\bin
call %xv_path%/xsim s_behav -key {Behavioral:sim_1:Functional:s} -tclbatch s.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
