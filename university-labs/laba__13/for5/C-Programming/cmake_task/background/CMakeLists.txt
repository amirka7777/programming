# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes

add_library(BACK STATIC background.c)

target_link_libraries(BACK PIPES)