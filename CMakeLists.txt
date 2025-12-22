cmake_minimum_required(VERSION 3.15)
project(tetriz)
set(CMAKE_CXX_STANDARD 20)

aux_source_directory(. SRC)

add_executable(tetriz ${SRC})