@echo off
setlocal

:: 1. Configuration
set PROJECT_NAME=Currency Converter v2.1 (PostgreSQL)
set VCPKG_PATH=C:\Users\Administrador\vcpkg\installed\x64-windows
set VCVARS="C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"

echo [%PROJECT_NAME% - Starting Build]

:: 2. Initialize MSVC Environment
if not exist %VCVARS% (
    echo [!] Error: vcvars64.bat not found at specified path.
    echo Please check your Visual Studio installation path.
    goto :error
)

call %VCVARS%

:: 3. Compilation
echo [Info] Compiling source files with C++20 standard...
cl /EHsc /std:c++20 src/*.cpp ^
    /I "include" ^
    /I "%VCPKG_PATH%\include" ^
    /link /LIBPATH:"%VCPKG_PATH%\lib" ^
    libcurl.lib pqxx.lib libpq.lib ws2_32.lib crypt32.lib advapi32.lib ^
    /out:converter.exe

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [!] Build failed. Please check the error messages above.
    goto :error
)

:: 4. Post-Build: Dependency management
echo [Info] Deployment: Copying required DLLs...
xcopy /y "%VCPKG_PATH%\bin\libcurl.dll" . >nul
xcopy /y "%VCPKG_PATH%\bin\pqxx.dll" . >nul
xcopy /y "%VCPKG_PATH%\bin\libpq.dll" . >nul
xcopy /y "%VCPKG_PATH%\bin\libcrypto-*.dll" . >nul
xcopy /y "%VCPKG_PATH%\bin\libssl-*.dll" . >nul

echo [Build Successful!]
echo.
echo Setup complete. Configure your .env file and run: converter.exe
goto :fim

:error
exit /b %ERRORLEVEL%

:fim
pause