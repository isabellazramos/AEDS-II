cmake_minimum_required(VERSION 3.15)
project(bst_tree C)

set(CMAKE_C_STANDARD 99)

add_executable(bst_tree main.c bst_tree.h bst_tree.c)