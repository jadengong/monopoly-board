cmake_minimum_required(VERSION 3.16)
project(monopoly-board)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check if building for WebAssembly
if(EMSCRIPTEN)
    message(STATUS "Building for WebAssembly with Emscripten")
    
    # WebAssembly-specific settings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_PTHREADS=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s DISABLE_EXCEPTION_CATCHING=0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s EXPORTED_RUNTIME_METHODS=['ccall','cwrap','addFunction']")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s MODULARIZE=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s EXPORT_NAME='MonopolyBoardWASM'")
    
    # Create WebAssembly executable
    add_executable(monopoly_board_wasm
            "main_wasm.cpp"
            "MonopolyBoard.cpp")
    
    # Set output properties for WebAssembly
    set_target_properties(monopoly_board_wasm PROPERTIES
            SUFFIX ".html"
            LINK_FLAGS "-s WASM=1 -s EXPORTED_RUNTIME_METHODS=['ccall','cwrap'] -s EXPORTED_FUNCTIONS=['_main','_malloc','_free','_initializeGame','_getAllProperties','_addProperty','_searchProperty','_sortProperties','_getPropertiesByColor','_getGameStats','_deleteProperty','_getPropertyCount','_cleanup'] -s MODULARIZE=1 -s EXPORT_NAME='MonopolyBoardWASM' --bind"
    )
    
    # Include directories for headers
    target_include_directories(monopoly_board_wasm PRIVATE .)
    
else()
    # Regular C++ build
    message(STATUS "Building for native C++")
    
    # Add all source files
    add_executable(sdsu_projects
            "main.cpp"
            "MonopolyBoard.cpp")
    
    # Include directories for headers
    target_include_directories(sdsu_projects PRIVATE .)
endif()