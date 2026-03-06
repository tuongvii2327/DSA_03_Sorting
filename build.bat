@echo off
SETLOCAL EnableDelayedExpansion

:: 1. Cấu hình tên file đầu ra và trình biên dịch
set OUTPUT=groupid.exe
set COMPILER=g++
set FLAGS=-O3 -Iinclude -Iinclude/algorithm

:: 2. Thu thập tất cả các file .cpp từ thư mục source và các thư mục con
set SOURCES=source/*.cpp source/algorithm/*.cpp

echo -------------------------------------------------------
echo Compiling DSA Sorting Project...
echo Compiler: %COMPILER%
echo Flags: %FLAGS%
echo -------------------------------------------------------

:: 3. Thực hiện lệnh biên dịch
%COMPILER% %FLAGS% %SOURCES% -o %OUTPUT%

:: 4. Kiểm tra lỗi biên dịch
if %ERRORLEVEL% EQU 0 (
    echo.
    echo [SUCCESS] Compilation finished.
    echo [INFO] Executable created: %OUTPUT%
    echo -------------------------------------------------------
) else (
    echo.
    echo [ERROR] Compilation failed! Please check your code.
    pause
)

ENDLOCAL