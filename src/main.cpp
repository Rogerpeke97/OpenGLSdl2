// To compile with gcc:  (tested on Ubuntu 14.04 64bit):
//	 g++ sdl2_opengl.cpp -lSDL2 -lGL
// To compile with msvc: (tested on Windows 7 64bit)
//   cl sdl2_opengl.cpp /I C:\sdl2path\include /link C:\path\SDL2.lib C:\path\SDL2main.lib /SUBSYSTEM:CONSOLE /NODEFAULTLIB:libcmtd.lib opengl32.lib
#define GL_GLEXT_PROTOTYPES
#include <iostream>
#include <stdio.h>
#include <stdint.h> 
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>
#include <fstream>
#include <string> /*for getLine()*/
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"
#include "scene/parallelepiped.cpp"


// typedef int32_t i32;
// typedef uint32_t u32;
typedef int32_t b32;

int main (){

  unsigned short window_width;

  unsigned short window_height;

  SDL_DisplayMode DM;

  SDL_Init(SDL_INIT_VIDEO);

  for(int i = 0; i < SDL_GetNumVideoDisplays(); ++i){

    int should_be_zero = SDL_GetCurrentDisplayMode(i, &DM);

    if(should_be_zero != 0)
      SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());

    else
    window_width = DM.w;
    window_height = DM.h;
  }

  SDL_Quit();

  SDL_GetCurrentDisplayMode(0, &DM);
  
  unsigned int WindowFlags = SDL_WINDOW_OPENGL;

  SDL_Window *Window = SDL_CreateWindow("OpenGL Test", 0, 0, window_width, window_height, WindowFlags);
  assert(Window);
  SDL_GLContext Context = SDL_GL_CreateContext(Window);

  // setup Dear ImGui context
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

  ImGui::StyleColorsDark();

  ImGui_ImplSDL2_InitForOpenGL(Window, Context);
  ImGui_ImplOpenGL3_Init("#version 320 es");

  ImVec4 background = ImVec4(35/255.0f, 35/255.0f, 35/255.0f, 1.00f);

  b32 Running = 1;
  b32 FullScreen = 0;
  while (Running){
    SDL_Event Event;
    while (SDL_PollEvent(&Event)){
      ImGui_ImplSDL2_ProcessEvent(&Event);
      if (Event.type == SDL_KEYDOWN){
        switch (Event.key.keysym.sym){
          case SDLK_ESCAPE:
            Running = 0;
          break;
          case SDLK_f:
            FullScreen = !FullScreen;
            if (FullScreen){
              SDL_SetWindowFullscreen(Window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
            }
            else{
              SDL_SetWindowFullscreen(Window, WindowFlags);
            }
            break;
            default:
            break;
        }
      }
      else if (Event.type == SDL_QUIT){
        Running = 0;
      }
    }
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(Window);

    glViewport(0, 0, window_width, window_height);
    glClearColor(0.588f, 0.294f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);
    createParallelepiped();
    SDL_GL_SwapWindow(Window);
  }
  return 0;
}