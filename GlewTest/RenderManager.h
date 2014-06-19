#pragma once

#include <GL/glew.h>
#include "ShaderInterface.h"
#include <QVector3D>
#include <QMatrix4x4>
#include <QGLWidget>

typedef struct {
	float location[3];
	float tex[2];
	float normal[3];
	float color[3];
	char padding[20];
} Vertex;

typedef struct {
	int shaderMode;
	int texId;
	GLenum geometryType;
	int count;
	uint vao;
} VAOShape;

class RenderManager {
public:
	GLuint program;
	std::vector<VAOShape> vao_list;

	GLuint vertexLoc;
	GLuint texLoc;
	GLuint normalLoc;
	GLuint colorLoc;

	QHash<QString, GLuint> nameToTexId;

public:
	RenderManager() {}

	uint init();
	void render();
	void addShape(GLenum geometryType, std::vector<Vertex> &points);
	uint loadTexture(QGLWidget* glWidget, QString filename);
};

