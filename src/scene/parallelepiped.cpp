

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

  const std::string shaderFileParsedVertex = parseShader("./shaders/parallelepiped.shader", GL_VERTEX_SHADER);
  const std::string shaderFileParsedColor = parseShader("./shaders/parallelepiped.shader", GL_VERTEX_SHADER);

  const char *vertexShaderData = shaderFileParsedVertex.c_str();

  const char *colorShaderData = shaderFileParsedColor.c_str();

  // std:: cout << shaderFileParsedVertex << std::endl;
  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  //Create parallelepiped
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.8f,  0.5f, 0.0f,

    -0.5f, -0.5f, 0.0f,
    -0.2f, 0.5f, 0.0f,
    0.8f, 0.5f, 0.0f
  };

  //shaders  
  unsigned int VBO;

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glShaderSource(vertexShader, 1, &vertexShaderData, NULL);
  glShaderSource(fragmentShader, 1, &colorShaderData, NULL);

  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  //Shader program 
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  

  int  success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }

}