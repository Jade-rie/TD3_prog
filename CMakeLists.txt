# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.10)

# La version du C++ que l'on souhaite utiliser (dans notre cas C++17)
set(CMAKE_CXX_STANDARD 17)

# Le nom du projet
project(IMAC_project)

# add_executable(positifnegatif positifnegatif.cpp)
add_executable(ex1 ex1.cpp)
add_executable(ex2 ex2.cpp)