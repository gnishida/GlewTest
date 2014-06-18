#include "Cube.h"

Cube::Cube(float dx, float dy, float dz, const QColor& color) {
	Vertex v;

	v.color[0] = color.redF(); v.color[1] = color.greenF(); v.color[2] = color.blueF();

	// add bottom face
	v.normal[0] = 0.0f; v.normal[1] = 0.0f; v.normal[2] = -1.0f;
	v.location[0] = -dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);

	// add top face
	v.normal[0] = 0.0f; v.normal[1] = 0.0f; v.normal[2] = 1.0f;
	v.location[0] = -dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);

	// add front face
	v.normal[0] = 0.0f; v.normal[1] = -1.0f; v.normal[2] = 0.0f;
	v.location[0] = -dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);

	// add right face
	v.normal[0] = 1.0f; v.normal[1] = 0.0f; v.normal[2] = 0.0f;
	v.location[0] = dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);

	// add left face
	v.normal[0] = -1.0f; v.normal[1] = 0.0f; v.normal[2] = 0.0f;
	v.location[0] = -dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = -dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);

	// add back face
	v.normal[0] = 0.0f; v.normal[1] = 1.0f; v.normal[2] = 0.0f;
	v.location[0] = dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = -dz * 0.5f;
	verts.push_back(v);
	v.location[0] = -dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
	v.location[0] = dx * 0.5f; v.location[1] = dy * 0.5f; v.location[2] = dz * 0.5f;
	verts.push_back(v);
}

void Cube::translate(float dx, float dy, float dz) {
	for (int i = 0; i < verts.size(); ++i) {
		verts[i].location[0] += dx;
		verts[i].location[1] += dy;
		verts[i].location[2] += dz;
	}
}
