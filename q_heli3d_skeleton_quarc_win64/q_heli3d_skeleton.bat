@call "C:\Users\s4291502\AppData\Roaming\MathWorks\MATLAB\R2012a\mexopts.bat"
@echo on
call "%VCINSTALLDIR%\vcvarsall.bat" x86_amd64
set MATLAB=C:\PROGRA~1\MATLAB\R2012a
nmake -f q_heli3d_skeleton.mk  GENERATE_REPORT=0 SHOW_TIMES=0 DEBUG=0 DEBUG_HEAP=0
