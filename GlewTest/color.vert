#version 330
 
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 tex;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec3 color;

out vec3 vPosition;
out vec2 vUV;
out vec3 vNormal;
out vec3 vColor;

uniform int mode;
uniform mat4 viewMatrix, projMatrix;

void main()
{
	vPosition = position;
	vUV = tex;
	vNormal = normal;
    vColor = color;
    gl_Position = projMatrix * viewMatrix * vec4(position, 1.0);
}