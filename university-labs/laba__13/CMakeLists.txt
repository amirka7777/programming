set(KUKU src/main.c)

cmake_minimum_required(VERSION 3.10)

project(laba__13 C)

option(BUILD_SHARED_LIBS "shared lib(on/off)" OFF)

include_directories(include)

add_library(cars_lib src/carsFunction.c)

add_executable(program ${KUKU})

target_link_libraries(program cars_lib)