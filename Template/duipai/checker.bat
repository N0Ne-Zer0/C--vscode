@echo off
set /a cnt=0

:loop
set /a cnt+=1
echo ===============================
echo Running Test %cnt% ...

REM 1. 运行数据生成器（必须确保 data.exe 已经编译好）
data.exe > in.txt

REM 2. 运行暴力/正确程序（std.exe）
std.exe < in.txt > std.out

REM 3. 运行你的待测程序（test.exe）
test.exe < in.txt > test.out

REM 4. 比较两个输出文件
fc std.out test.out > nul

REM 如果 fc 发现不同，errorlevel 会变成 1，跳转到报错
if errorlevel 1 goto error

echo Accepted!
echo ===============================
goto loop


:error
echo ===============================
echo Wrong Answer on Test %cnt%!
echo 发现错误数据！请打开该目录下的 in.txt 查看输入。
pause