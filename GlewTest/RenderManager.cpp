#include "RenderManager.h"
#include <iostream>

uint RenderManager::init() {
	program = ShaderInterface::initShader("color.vert", "color.frag");
 
    vertexLoc = glGetAttribLocation(program, "position");
    colorLoc = glGetAttribLocation(program, "color");
  
	glUseProgram(program);

    return(program);
}

void RenderManager::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	for (int i = 0; i < vao_list.size(); ++i) {
		glBindVertexArray(vao_list[i].vao);
		glDrawArrays(vao_list[i].mode, 0, vao_list[i].count);
	}
}

void RenderManager::setup() {
	// add two triangles
	std::vector<Vertex> points;
	Vertex v;
	v.location[0] = -3.0f; v.location[1] = 0.0f; v.location[2] = -5.0f;
	v.color[0] = 0.0f; v.color[1] = 0.0f; v.color[2] = 1.0f;
	points.push_back(v);
	v.location[0] = -1.0f; v.location[1] = 0.0f; v.location[2] = -5.0f;
	points.push_back(v);
	v.location[0] = -2.0f; v.location[1] = 2.0f; v.location[2] = -5.0f;
	points.push_back(v);

	v.location[0] = 1.0f; v.location[1] = 0.0f; v.location[2] = -5.0f;
	v.color[0] = 1.0f; v.color[1] = 0.0f; v.color[2] = 0.0f;
	points.push_back(v);
	v.location[0] = 3.0f; v.location[1] = 0.0f; v.location[2] = -5.0f;
	points.push_back(v);
	v.location[0] = 2.0f; v.location[1] = 2.0f; v.location[2] = -5.0f;
	points.push_back(v);

	addShape(GL_TRIANGLES, points);

	// add axis
	points.clear();

	v.location[0] = -20.0f; v.location[1] = 0.0f; v.location[2] = 0.0f;
	v.color[0] = 0.0f; v.color[1] = 0.0f; v.color[2] = 0.0f;
	points.push_back(v);
	v.location[0] = 20.0f; v.location[1] = 0.0f; v.location[2] = 0.0f;
	points.push_back(v);
	v.location[0] = 0.0f; v.location[1] = -20.0f; v.location[2] = 0.0f;
	points.push_back(v);
	v.location[0] = 0.0f; v.location[1] = 20.0f; v.location[2] = 0.0f;
	points.push_back(v);
	v.location[0] = 0.0f; v.location[1] = 0.0f; v.location[2] = -20.0f;
	points.push_back(v);
	v.location[0] = 0.0f; v.location[1] = 0.0f; v.location[2] = 20.0f;
	points.push_back(v);

	addShape(GL_LINES, points);
}

void RenderManager::addShape(GLenum mode, std::vector<Vertex> &points) {
    GLuint vbo;
 
	VAOShape vaoShape;
	vaoShape.mode = mode;
	vaoShape.count = points.size();
    glGenVertexArrays(1, &vaoShape.vao);
	vao_list.push_back(vaoShape);

    glBindVertexArray(vaoShape.vao);

    // Generate two slots for the vertex and color buffers
    glGenBuffers(1, &vbo);

	// bind buffer for vertices and copy data into buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * points.size(), points.data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(vertexLoc);
	glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, location));
 
    glEnableVertexAttribArray(colorLoc);
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, color));
}

