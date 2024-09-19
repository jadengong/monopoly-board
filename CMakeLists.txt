cmake_minimum_required(VERSION 3.29)
project(sdsu_projects)

set(CMAKE_CXX_STANDARD 20)

add_executable(classMain test.cpp)
add_executable(sdsu_projects
        "monopoly_boardMW.cpp")