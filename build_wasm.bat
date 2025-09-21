@echo off
REM Build script for WebAssembly compilation on Windows
REM This script compiles the Monopoly Board C++ code to WebAssembly

echo 🎯 Building Monopoly Board for WebAssembly...

REM Check if Emscripten is installed
where emcc >nul 2>nul
if %errorlevel% neq 0 (
    echo ❌ Emscripten not found. Please install Emscripten first:
    echo    git clone https://github.com/emscripten-core/emsdk.git
    echo    cd emsdk
    echo    emsdk install latest
    echo    emsdk activate latest
    echo    emsdk_env.bat
    pause
    exit /b 1
)

REM Create build directory
if not exist build_wasm mkdir build_wasm
cd build_wasm

echo 📦 Compiling C++ to WebAssembly...

REM Compile with Emscripten
emcc -std=c++20 ^
     -O3 ^
     -s WASM=1 ^
     -s EXPORTED_RUNTIME_METHODS="['ccall','cwrap','addFunction']" ^
     -s EXPORTED_FUNCTIONS="['_main','_malloc','_free','_initializeGame','_getAllProperties','_addProperty','_searchProperty','_sortProperties','_getPropertiesByColor','_getGameStats','_deleteProperty','_getPropertyCount','_cleanup']" ^
     -s MODULARIZE=1 ^
     -s EXPORT_NAME="MonopolyBoardWASM" ^
     -s ALLOW_MEMORY_GROWTH=1 ^
     -s DISABLE_EXCEPTION_CATCHING=0 ^
     -s USE_PTHREADS=1 ^
     -s ASSERTIONS=0 ^
     --bind ^
     -I../ ^
     ../main_wasm.cpp ^
     ../MonopolyBoard.cpp ^
     -o monopoly_board_wasm.js

if %errorlevel% equ 0 (
    echo ✅ WebAssembly compilation successful!
    echo 📁 Generated files:
    echo    - monopoly_board_wasm.js
    echo    - monopoly_board_wasm.wasm
    
    REM Copy HTML file to build directory
    copy ..\index.html .
    
    echo.
    echo 🚀 To run the web app:
    echo    1. Start a local web server in the build_wasm directory
    echo    2. Open http://localhost:8000 in your browser
    echo.
    echo 💡 Quick start with Python:
    echo    cd build_wasm ^&^& python -m http.server 8000
    echo.
    echo 💡 Quick start with Node.js:
    echo    cd build_wasm ^&^& npx serve .
    
) else (
    echo ❌ WebAssembly compilation failed!
    pause
    exit /b 1
)

pause
