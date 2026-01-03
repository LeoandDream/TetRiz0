cmake_minimum_required(VERSION 3.15)
project(tetriz)
set(CMAKE_CXX_STANDARD 20)

aux_source_directory(./src SRC)
include_directories(./include)

add_executable(tetriz ${SRC})
target_link_libraries(tetriz pthread)