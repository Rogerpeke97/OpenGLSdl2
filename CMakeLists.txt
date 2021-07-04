cmake_minimum_required(VERSION 3.20.5)

project(OPENGLPROJECT2 VERSION 0.1.0)

add_executable(OPENGLPROJECT2 src/main.cpp)

target_link_libraries(OPENGLPROJECT2 SDL2main SDL2 GL)