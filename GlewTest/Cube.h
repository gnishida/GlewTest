#pragma once

#include <vector>
#include <QVector3D>
#include <QColor>
#include "RenderManager.h"

class Cube {
public:
	std::vector<Vertex> verts;

public:
	Cube(float dx, float dy, float dz, const QColor& color);
	
	void translate(float dx, float dy, float dz);
};

