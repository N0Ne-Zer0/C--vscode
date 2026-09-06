@echo off
set /a cnt=0

:loop
set /a cnt+=1
echo ===============================
echo Running Test %cnt% ...

data.exe > in.txt
std.exe < in.txt > std.out
test.exe < in.txt > test.out
fc std.out test.out > nul

if errorlevel 1 goto error

echo Accepted!
echo ===============================
goto loop

:error
echo ===============================
echo Wrong Answer on Test %cnt%!
echo 发现错误数据！请打开该目录下的 in.txt 查看输入。
pause