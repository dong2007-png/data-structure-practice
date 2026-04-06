cmake_minimum_required(VERSION 3.20)
project(data_structure)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 自动递归编译所有子目录的.cpp文件
file(GLOB_RECURSE ALL_SOURCES "*.cpp" "**/*.cpp")

add_executable(data_structure main.cpp ${ALL_SOURCES})