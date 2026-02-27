#[[
Здесь ваша реализация
]]

cmake_minimum_required(VERSION 3.10)

project(laba__13__for5)



include_directories(
    /home/amir/programming/university-labs/laba__13/for5/C-Programming/cmake_task/pipes 
    /home/amir/programming/university-labs/laba__13/for5/C-Programming/cmake_task/background 
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/pipes)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/background)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

target_link_libraries(main BACK)