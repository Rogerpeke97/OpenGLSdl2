

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


void createParallelepiped(){
  //If you want to use SDL_opengl.h define GL_GLEXT_PROTOTYPES before including it.

  const std::string shaderFileParsedVertex = parseShader("./shaders/parallelepiped.shader", GL_VERTEX_SHADER);
  const std::string shaderFileParsedColor = parseShader("./shaders/parallelepiped.shader", GL_FRAGMENT_SHADER);

  // std::cout << shaderFileParsedColor << std::endl;
  // std::cout << shaderFileParsedVertex << std::endl;


  const char *vertexShaderData = shaderFileParsedVertex.c_str();

  const char *colorShaderData = shaderFileParsedColor.c_str();

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


  unsigned int VAO;
  glGenVertexArrays(1, &VAO); 
  glBindVertexArray(VAO);


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

  glLinkProgram(shaderProgram);
  

  int success;
  char infoLog[512];
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if(!success)
  {
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);  

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);


  int programSuccess;
  char infoProgramLog[512];
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &programSuccess);
  if(!programSuccess){
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoProgramLog);
    std::cout << "Error with the program shader \n" << infoProgramLog << std::endl;
  }

  glUseProgram(shaderProgram);
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 6);
}