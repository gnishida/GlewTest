#version 330
 
uniform mat4 viewMatrix, projMatrix;

/*
in vec3 position;
in vec3 color;
in vec3 normal;
*/

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec3 normal;

out vec3 vPosition;
out vec3 vColor;
out vec3 vNormal;

void main()
{
	vPosition = position;
    vColor = color;
	vNormal = normal;
    gl_Position = projMatrix * viewMatrix * vec4(position, 1.0);
}