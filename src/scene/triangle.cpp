

static std::string parseShader(const std::string& filepath, unsigned int type) {
    std::ifstream streamFile(filepath);

    std::string shaders_line;

    unsigned int type_to_add;

    std::string shader;

    while (getline(streamFile, shaders_line)) {
        // Output the text from the file
        if (shaders_line.find("#shader vertex") != std::string::npos) {
            type_to_add = GL_VERTEX_SHADER;

        }
        else if(shaders_line.find("#shader fragment") != std::string::npos) {
            type_to_add = GL_FRAGMENT_SHADER;
        }
        else {
            if (type_to_add == type) {
                shader += shaders_line + "\n";
            }
        }
    }
    return shader;
}


void createTriangle(){
  //If you want to use SDL_opengl.h define GL_GLEXT_PROTOTYPES before including it.
  std:: cout << "triangle.cpp works! /n;" << std::endl;
  //Create parallepiped
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.8f,  0.5f, 0.0f,

    -0.5f, -0.5f, 0.0f,
    -0.2f, 0.5f, 0.0f,
    0.8f, 0.5f, 0.0f
  };  
  unsigned int VBO;
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}