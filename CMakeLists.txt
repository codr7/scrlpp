cmake_minimum_required(VERSION 3.5)

project(scrl)

set(CMAKE_CXX_COMPILER clang++)

add_compile_options(-std=c++20 -fno-exceptions -Wall -Werror -O2 -g)

file(GLOB_RECURSE SRC src/scrl/*.cpp)

add_executable(exe ${SRC} src/main.cpp)
set_target_properties(exe PROPERTIES OUTPUT_NAME scrl)
target_include_directories(exe PUBLIC src/)

add_library(lib STATIC ${SRC})
set_target_properties(lib PROPERTIES OUTPUT_NAME scrl)
target_include_directories(lib PUBLIC src/)

install(FILES build/libscrl.a DESTINATION lib)
install(FILES build/scrl DESTINATION bin)
