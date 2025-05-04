cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(gb C ASM)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${PROCESSOR_FLAGS} ${COMILATION_FLAG} -Wall -Wextra -g -O0")

file(GLOB_RECURSE SOURCE "src/*.c")
include_directories(src)

add_executable(${PROJECT_NAME}.elf ${SOURCE})
