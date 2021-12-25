#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H
#include "../Scene.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
private:
  float cameraSpeed = 0.1f;

  glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);

  glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);

  glm::vec3 cameraDirectionZ;

  glm::vec3 cameraDirectionY;

public:
  void setupCamera(Scene scene);

  void updateCamera(std::string translationDirection);
  
};

#endif