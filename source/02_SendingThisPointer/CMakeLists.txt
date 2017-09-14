cmake_minimum_required(VERSION 3.5)
project(02_SendingThisPointer)

set(CMAKE_CXX_COMPILER "clang++")
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Threads REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME})

file(GLOB COMPILABLE_SOURCES 
        RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/*_C_*.cpp)

message(STATUS "Chapter: ${PROJECT_NAME}")
        
foreach(testsourcefile ${COMPILABLE_SOURCES})
    string(REPLACE ".cpp" "" testname ${testsourcefile})
    add_executable(${testname} ${testsourcefile})
    target_link_libraries(${testname} Threads::Threads)
endforeach(testsourcefile ${COMPILABLE_SOURCES})
