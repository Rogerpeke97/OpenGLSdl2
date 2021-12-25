#include "Camera.h"
#include "../Scene.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void Camera::setupCamera(Scene scene)
{

  cameraDirectionZ = glm::normalize(cameraPosition - cameraTarget);

  glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); 

  glm::vec3 cameraDirectionX = glm::normalize(glm::cross(up, cameraDirectionZ));

  cameraDirectionY = glm::cross(cameraDirectionZ, cameraDirectionX);

  // const float radius = 10.0f;
  // float camX = sin(SDL_GetTicks()) * radius;
  // float camZ = cos(SDL_GetTicks()) * radius;
  glm::mat4 view;
  view = glm::lookAt(cameraPosition, cameraPosition + cameraDirectionZ, cameraDirectionY);


  glUniformMatrix4fv(glGetUniformLocation(scene.getShaderProgram(), "view"), 1, GL_FALSE, &view[0][0]);

  std::cout << "Camera direction: " << cameraDirectionZ.x << " " << cameraDirectionZ.y << " " << cameraDirectionZ.z << std::endl;

}

void Camera::updateCamera(std::string translationDirection){

  std::cout << "Translation direction: " << translationDirection <<  std::endl;
  if(translationDirection == "z"){
    std::cout << "Translation direction: " << translationDirection <<  std::endl;
    cameraPosition += cameraSpeed * cameraDirectionZ;
  }

    // if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    //     cameraPos += cameraSpeed * cameraFront;
    // if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    //     cameraPos -= cameraSpeed * cameraFront;
    // if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    //     cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    // if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    //     cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

}