#pragma once

#include <GL/glew.h>
#include "ShaderInterface.h"
#include <QVector3D>
#include <QMatrix4x4>

typedef struct {
	float location[3];
	float tex[2];
	float normal[3];
	float color[3];
	char padding[20];
} Vertex;

typedef struct {
	GLenum mode;
	int count;
	uint vao;
} VAOShape;

class RenderManager {
public:
	GLuint program;
	std::vector<VAOShape> vao_list;

	GLuint vertexLoc;
	GLuint colorLoc;

public:
	RenderManager() {}

	uint init();
	void render();
	void setup();
	void addShape(GLenum mode, std::vector<Vertex> &points);
};

