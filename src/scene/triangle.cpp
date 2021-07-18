

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
  const std::string shaderFileParsed = parseShader("./shaders/triangle.shader", GL_VERTEX_SHADER);
  const char *vertexShaderData = shaderFileParsed.c_str();

  std:: cout << shaderFileParsed << std::endl;
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
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

  glShaderSource(vertexShader, 1, &vertexShaderData, NULL);

  glCompileShader(vertexShader);


  int  success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }

}