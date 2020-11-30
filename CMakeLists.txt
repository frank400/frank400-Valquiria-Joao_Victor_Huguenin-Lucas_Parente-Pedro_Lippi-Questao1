cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

project(jogo_da_vida)

add_executable(
        test
        src/main.c
        src/operacoes_matrix.c
        src/system_operations.c
)