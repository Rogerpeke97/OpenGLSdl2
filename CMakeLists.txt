cmake_minimum_required(VERSION 3.16.3)

# set(CMAKE_CXX_FLAGS "-std=c++14")


project(OPENGLPROJECT2 VERSION 0.1.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(sources
    src/main.cpp
    src/imgui/imconfig.h
    src/imgui/imgui.cpp
    src/imgui/imgui.h
    src/imgui/imgui_demo.cpp
    src/imgui/imgui_draw.cpp
    src/imgui/imgui_internal.h
    src/imgui/imgui_widgets.cpp
    src/imgui/imstb_rectpack.h
    src/imgui/imstb_textedit.h
    src/imgui/imstb_truetype.h
    src/imgui/imgui_impl_opengl3.cpp
    src/imgui/imgui_impl_opengl3.h
    src/imgui/imgui_impl_sdl.cpp
    src/imgui/imgui_impl_sdl.h
    src/imgui/imgui_tables.cpp
)


add_executable(OPENGLPROJECT2 ${sources})

target_link_libraries(OPENGLPROJECT2 SDL2main SDL2 GL)
target_link_libraries(OPENGLPROJECT2 ${CMAKE_DL_LIBS})
