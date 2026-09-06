@echo off
set /a cnt=0

:loop
set /a cnt+=1
echo ===============================
echo Running Test %cnt% ...

data.exe > in.txt
test.exe < in.txt > test.out
spj.exe

if errorlevel 1 goto error

echo Accepted!
echo ===============================
goto loop

:error
echo ===============================
echo Wrong Answer on Test %cnt%!
echo 发现错误数据！请检查 in.txt 和 test.out。
pause