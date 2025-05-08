cmake_minimum_required(VERSION 3.10)

project(matrixProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(matrixProjectApp
    src/matrix.cpp
    src/squareMatrix.cpp
    src/main.cpp
)    