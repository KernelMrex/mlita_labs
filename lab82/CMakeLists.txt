cmake_minimum_required(VERSION 3.23)
project(mlita_labs_lab82)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        lab82_1
        src/main_multiplication.cpp
        src/lib/Permutation.h
)

add_executable(
        lab82_2
        src/main_permutation.cpp
        src/lib/Permutation.h
)

add_executable(
        lab82_3
        src/main_inversion.cpp
        src/lib/Permutation.h
        src/lib/InversionVector.h
)