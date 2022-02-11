#shader vertex
#version 320 es 

layout(location = 0) in vec4 position;

uniform mat4 cameraMatrix;

void main()
{
   gl_Position = cameraMatrix * position;
};

#shader fragment
#version 320 es 

out lowp vec4 color;

void main()
{
   color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
};