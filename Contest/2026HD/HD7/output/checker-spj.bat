@echo off
set /a cnt=0

:loop
set /a cnt+=1
echo ===============================
echo Running Test %cnt% ...

REM 1. 运行数据生成器
data.exe > in.txt

REM 2. 运行你的待测程序
test.exe < in.txt > test.out

REM 3. 运行 SPJ 校验程序（它会自动读取当前目录下的文件）
spj.exe

REM 4. 捕捉 SPJ 的返回值。如果 spj.cpp 返回了 1 (或其他非0值)，就会跳转到 error
if errorlevel 1 goto error

echo Accepted!
echo ===============================
goto loop


:error
echo ===============================
echo Wrong Answer on Test %cnt%!
echo 发现错误数据！请检查 in.txt 和 test.out。
pause