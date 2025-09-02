cmake_minimum_required(VERSION 3.29)
project(monopoly-board)

set(CMAKE_CXX_STANDARD 20)

# Add all source files
add_executable(sdsu_projects
        "main.cpp"
        "MonopolyBoard.cpp")

# Include directories for headers
target_include_directories(sdsu_projects PRIVATE .)