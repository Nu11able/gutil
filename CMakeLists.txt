cmake_minimum_required(VERSION 3.5)
project(GameServer)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB EXAMPLES example/*.cpp)
foreach(file_path ${EXAMPLES})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" file_name ${file_path})
    add_executable(${file_name} ${file_path})
endforeach(file_path ${TEST_FILES})

