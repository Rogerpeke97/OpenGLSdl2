class Scene
{

public:

 unsigned int vertexShader;

 unsigned int VBO;

 unsigned int fragmentShader;

 const char *vertexShaderData;

 const char *colorShaderData;

 unsigned int VAO;

 unsigned int EBO;

 void setup();

 static std::string parseShader(const std::string &filepath, unsigned int type);

 void render();

};
