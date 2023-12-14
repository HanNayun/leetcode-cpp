cmake_minimum_required(VERSION 3.26)
project(leetcode)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(source)
add_subdirectory(test)

include_directories(include)

set(INCLUDE_FILES
        include/list_node.cc
        include/list_node.h
        include/algorithm/Search.h
        include/next_tree_node.h
        include/tree_node.h
)

set(SOURCE_FILES
        main.cc
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(${PROJECT_NAME} source)