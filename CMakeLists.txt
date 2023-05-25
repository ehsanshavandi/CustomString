cmake_minimum_required(VERSION 3.5)

project(stl_string_sream_101 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stl_string_sream_101
    src/main.cpp
    src/customstring.hpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include)

install(TARGETS stl_string_sream_101
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
