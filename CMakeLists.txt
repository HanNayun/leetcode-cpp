cmake_minimum_required(VERSION 3.26)
project(leetcode)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(source)
add_subdirectory(test)

set(SOURCE_FILES main.cc
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} source)