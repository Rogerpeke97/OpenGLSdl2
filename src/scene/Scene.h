#ifndef SCENE_CLASS_H
#define SCENE_CLASS_H

#include "camera/Camera.h"

class Scene

{
private:
  unsigned int vertexShader;

  unsigned int VBO;

  unsigned int fragmentShader;

  const char *vertexShaderData;

  const char *colorShaderData;

  unsigned int VAO;

  unsigned int EBO;

  unsigned int shaderProgram;

  public:

  void setup(Camera camera);

  static std::string parseShader(const std::string &filepath, unsigned int type);

  void render();

  unsigned int getShaderProgram();

};


#endif