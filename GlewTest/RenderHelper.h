#pragma once

#include <vector>
#include <QVector3D>
#include <QColor>
#include "RenderManager.h"
#include "Cube.h"
#include "Sphere.h"

class RenderHelper {
protected:
	RenderHelper() {}
	~RenderHelper() {}

public:
	static void addCube(RenderManager& renderManager, Cube& cube, const QColor &color);
	static void addSphere(RenderManager& renderManager, Sphere& sphere, const QColor &color);
};

