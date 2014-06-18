#pragma once

#include <vector>
#include <QColor>
#include "RenderManager.h"

class Sphere {
public:
	std::vector<Vertex> verts;

public:
	Sphere(float radius, const QColor& color, int slice = 20, int stack = 20);
	
	void translate(float dx, float dy, float dz);
};

