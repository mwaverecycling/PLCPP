cmake_minimum_required(VERSION 3.10)
project(PLCPP)

set(CMAKE_CXX_STANDARD 11)

## Install the executable to <install_directory>/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
## Install libraries (if any) to <install_directory>/bin
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE HEADERS ./include/*.hpp)
file(GLOB_RECURSE SOURCES ./src/*.cpp)


include_directories(include)
include_directories(include/builtin)
include_directories(include/builtin/debug)
include_directories(include/test)

add_library(plcpp STATIC
    ${SOURCES}
)

function(add_executable_test target source)
    add_executable(${target}
        ${source}
        ${HEADERS}
    )
    target_link_libraries(${target} plcpp)
endfunction()

add_executable_test(testrun test/test.cpp)