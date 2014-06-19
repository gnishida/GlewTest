#include "RenderManager.h"
#include <iostream>
#include <QFile>

uint RenderManager::init() {
	program = ShaderInterface::initShader("color.vert", "color.frag");
 
    vertexLoc = glGetAttribLocation(program, "position");
    texLoc = glGetAttribLocation(program, "tex");
    normalLoc = glGetAttribLocation(program, "normal");
    colorLoc = glGetAttribLocation(program, "color");
  
	glUseProgram(program);

    return(program);
}

void RenderManager::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	for (int i = 0; i < vao_list.size(); ++i) {
		glUniform1i (glGetUniformLocation (program, "mode"), vao_list[i].shaderMode);

		//if (vao_list[i].shaderMode == 2) {
			glBindTexture(GL_TEXTURE_2D, vao_list[i].texId);
		//}

		glUniform1i (glGetUniformLocation (program, "tex0"), 0);
		glBindVertexArray(vao_list[i].vao);
		glDrawArrays(vao_list[i].geometryType, 0, vao_list[i].count);
	}
}

void RenderManager::addShape(GLenum geometryType, std::vector<Vertex> &points) {
    GLuint vbo;
 
	VAOShape vaoShape;
	vaoShape.shaderMode = 1;
	vaoShape.texId = 0;
	vaoShape.geometryType = geometryType;
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
 
	glEnableVertexAttribArray(texLoc);
	glVertexAttribPointer(normalLoc, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, tex));

    glEnableVertexAttribArray(normalLoc);
	glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));

	glEnableVertexAttribArray(colorLoc);
	glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, color));

}

uint RenderManager::loadTexture(QGLWidget* glWidget, QString filename) {
	if (nameToTexId.contains(filename)) {
		return nameToTexId[filename];
	}

	if (!QFile::exists(filename)) {
		return NULL;
	}

	return glWidget->bindTexture(filename, GL_TEXTURE_2D);
}
