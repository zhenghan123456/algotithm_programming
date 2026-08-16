@echo off
chcp 65001 >nul
if "%~1"=="" (
    echo 用法: %0 源代码.cpp
    echo 示例: %0 main.cpp
    pause
    exit /b 1
)

set "SRC=%~1"
set "EXE=%~n1.exe"

:: MinGW g++ 竞赛编译参数，定义DEBUG宏
g++ "%SRC%" -o "%EXE%" ^
-std=c++17 ^
-O2 ^
-Wall ^
-Wextra ^
-Wshadow ^
-Wno‑sign‑conversion ^
-DDEBUG ^
-fno‑asm ^
-m64

if %errorlevel% neq 0 (
    echo 【编译失败】
    pause
    exit /b %errorlevel%
)

echo.
echo ====== 开始运行 %EXE% ======
:: 计时，使用powershell获取执行毫秒时间
powershell -Command "$sw=[System.Diagnostics.Stopwatch]::StartNew(); & '.\%EXE%'; $sw.Stop(); Write‑Host ''; Write‑Host ('程序运行耗时: {0:N3} 毫秒' -f $sw.Elapsed.TotalMilliseconds)"

:: 删除可执行文件
if exist "%EXE%" del "%EXE%"

echo.
echo 已清理可执行文件，脚本结束
pause
