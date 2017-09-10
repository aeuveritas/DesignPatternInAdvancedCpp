cmake_minimum_required(VERSION 3.5)
project(01_ThisPointer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME})

file(GLOB COMPILABLE_SOURCES 
        RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/*_C_*.cpp)

message(STATUS "Chapter: ${PROJECT_NAME}")
        
foreach(testsourcefile ${COMPILABLE_SOURCES})
    string(REPLACE ".cpp" "" testname ${testsourcefile})
    add_executable(${testname} ${testsourcefile})
endforeach(testsourcefile ${COMPILABLE_SOURCES})
