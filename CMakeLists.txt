cmake_minimum_required(VERSION 3.23)
project(AlgGauss)

set(CMAKE_CXX_STANDARD 23)

add_executable(AlgGauss main.cpp classes/Razionale.h classes/Matrice.cpp h/gblfun.h)
