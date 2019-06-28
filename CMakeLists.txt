cmake_minimum_required(VERSION 3.12.1)
project(fractol C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCES
        libft/*.h
        libft/*.c
        *.c
        *.h)

add_executable(fractol
        ${SOURCES})

#set(GCC_COVERAGE_COMPILE_FLAGS "-g -fno-omit-frame-pointer -fsanitize=address -Wall -Wextra -Werror")

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
target_link_libraries(fractol -lmlx "-framework OpenGL" "-framework AppKit")