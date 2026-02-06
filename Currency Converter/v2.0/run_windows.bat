@echo off
echo [Building Currency Converter v2.0]

:: Note: Update the path to vcvars64.bat based on your Visual Studio version (BuildTools/Community/etc.)
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

cd /d "%~dp0"

:: Note: Ensure the paths below match your vcpkg installation
cl /EHsc src\main.cpp src\CurrencyAPI.cpp src\InputHandler.cpp src\EnvLoader.cpp ^
   /I"include" /I"C:\path\to\vcpkg\installed\x64-windows\include" ^
   /link /LIBPATH:"C:\path\to\vcpkg\installed\x64-windows\lib" ^
   libcurl.lib ws2_32.lib wldap32.lib crypt32.lib advapi32.lib ^
   /OUT:converter.exe

if %errorlevel% neq 0 (
    echo [!] Build failed. Check your vcpkg paths.
    pause
    exit /b %errorlevel%
)

echo [Build Successful!]
converter.exe
pause