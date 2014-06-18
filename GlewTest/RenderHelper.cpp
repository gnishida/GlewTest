#include "RenderHelper.h"

void RenderHelper::addCube(RenderManager& renderManager, Cube& cube, const QColor &color) {
	QVector3D n;
	Vertex v;
	std::vector<Vertex> verts;

	v.color[0] = color.redF(); v.color[1] = color.greenF(); v.color[2] = color.blueF();

	// add bottom face
	n = QVector3D::crossProduct(cube.points[2] - cube.points[0], cube.points[1] - cube.points[0]);
	v.normal[0] = n.x(); v.normal[1] = n.y(); v.normal[2] = n.z();

	v.location[0] = cube.points[0].x(); v.location[1] = cube.points[0].y(); v.location[2] = cube.points[0].z();
	verts.push_back(v);
	v.location[0] = cube.points[3].x(); v.location[1] = cube.points[3].y(); v.location[2] = cube.points[3].z();
	verts.push_back(v);
	v.location[0] = cube.points[2].x(); v.location[1] = cube.points[2].y(); v.location[2] = cube.points[2].z();
	verts.push_back(v);
	v.location[0] = cube.points[1].x(); v.location[1] = cube.points[1].y(); v.location[2] = cube.points[1].z();
	verts.push_back(v);

	// add top face
	n = QVector3D::crossProduct(cube.points[5] - cube.points[4], cube.points[6] - cube.points[4]);
	v.normal[0] = n.x(); v.normal[1] = n.y(); v.normal[2] = n.z();

	v.location[0] = cube.points[4].x(); v.location[1] = cube.points[4].y(); v.location[2] = cube.points[4].z();
	verts.push_back(v);
	v.location[0] = cube.points[5].x(); v.location[1] = cube.points[5].y(); v.location[2] = cube.points[5].z();
	verts.push_back(v);
	v.location[0] = cube.points[6].x(); v.location[1] = cube.points[6].y(); v.location[2] = cube.points[6].z();
	verts.push_back(v);
	v.location[0] = cube.points[7].x(); v.location[1] = cube.points[7].y(); v.location[2] = cube.points[7].z();
	verts.push_back(v);

	// add front face
	n = QVector3D::crossProduct(cube.points[1] - cube.points[0], cube.points[5] - cube.points[0]);
	v.normal[0] = n.x(); v.normal[1] = n.y(); v.normal[2] = n.z();

	v.location[0] = cube.points[0].x(); v.location[1] = cube.points[0].y(); v.location[2] = cube.points[0].z();
	verts.push_back(v);
	v.location[0] = cube.points[1].x(); v.location[1] = cube.points[1].y(); v.location[2] = cube.points[1].z();
	verts.push_back(v);
	v.location[0] = cube.points[5].x(); v.location[1] = cube.points[5].y(); v.location[2] = cube.points[5].z();
	verts.push_back(v);
	v.location[0] = cube.points[4].x(); v.location[1] = cube.points[4].y(); v.location[2] = cube.points[4].z();
	verts.push_back(v);

	// add right face
	n = QVector3D::crossProduct(cube.points[2] - cube.points[1], cube.points[6] - cube.points[1]);
	v.normal[0] = n.x(); v.normal[1] = n.y(); v.normal[2] = n.z();

	v.location[0] = cube.points[1].x(); v.location[1] = cube.points[1].y(); v.location[2] = cube.points[1].z();
	verts.push_back(v);
	v.location[0] = cube.points[2].x(); v.location[1] = cube.points[2].y(); v.location[2] = cube.points[2].z();
	verts.push_back(v);
	v.location[0] = cube.points[6].x(); v.location[1] = cube.points[6].y(); v.location[2] = cube.points[6].z();
	verts.push_back(v);
	v.location[0] = cube.points[5].x(); v.location[1] = cube.points[5].y(); v.location[2] = cube.points[5].z();
	verts.push_back(v);

	// add left face
	n = QVector3D::crossProduct(cube.points[0] - cube.points[3], cube.points[4] - cube.points[3]);
	v.normal[0] = n.x(); v.normal[1] = n.y(); v.normal[2] = n.z();

	v.location[0] = cube.points[3].x(); v.location[1] = cube.points[3].y(); v.location[2] = cube.points[3].z();
	verts.push_back(v);
	v.location[0] = cube.points[0].x(); v.location[1] = cube.points[0].y(); v.location[2] = cube.points[0].z();
	verts.push_back(v);
	v.location[0] = cube.points[4].x(); v.location[1] = cube.points[4].y(); v.location[2] = cube.points[4].z();
	verts.push_back(v);
	v.location[0] = cube.points[7].x(); v.location[1] = cube.points[7].y(); v.location[2] = cube.points[7].z();
	verts.push_back(v);

	// add back face
	n = QVector3D::crossProduct(cube.points[3] - cube.points[2], cube.points[7] - cube.points[2]);
	v.normal[0] = n.x(); v.normal[1] = n.y(); v.normal[2] = n.z();

	v.location[0] = cube.points[2].x(); v.location[1] = cube.points[2].y(); v.location[2] = cube.points[2].z();
	verts.push_back(v);
	v.location[0] = cube.points[3].x(); v.location[1] = cube.points[3].y(); v.location[2] = cube.points[3].z();
	verts.push_back(v);
	v.location[0] = cube.points[7].x(); v.location[1] = cube.points[7].y(); v.location[2] = cube.points[7].z();
	verts.push_back(v);
	v.location[0] = cube.points[6].x(); v.location[1] = cube.points[6].y(); v.location[2] = cube.points[6].z();
	verts.push_back(v);

	renderManager.addShape(GL_QUADS, verts);
}

void RenderHelper::addSphere(RenderManager& renderManager, Sphere& sphere, const QColor &color) {
	Vertex v;
	QVector3D n;
	std::vector<Vertex> verts;

	for (int i = 0; i < sphere.points.size() / 3; ++i) {
		n = QVector3D::crossProduct(sphere.points[i * 3 + 2] - sphere.points[i * 3], sphere.points[i * 3 + 1] - sphere.points[i * 3]);
		n.normalize();
		v.normal[0] = n.x(); v.normal[1] = n.y(); v.normal[2] = n.z();

		v.color[0] = color.redF(); v.color[1] = color.greenF(); v.color[2] = color.blueF();

		v.location[0] = sphere.points[i * 3].x(); v.location[1] = sphere.points[i * 3].y(); v.location[2] = sphere.points[i * 3].z();
		verts.push_back(v);
		v.location[0] = sphere.points[i * 3 + 1].x(); v.location[1] = sphere.points[i * 3 + 1].y(); v.location[2] = sphere.points[i * 3 + 1].z();
		verts.push_back(v);
		v.location[0] = sphere.points[i * 3 + 2].x(); v.location[1] = sphere.points[i * 3 + 2].y(); v.location[2] = sphere.points[i * 3 + 2].z();
		verts.push_back(v);
	}

	renderManager.addShape(GL_TRIANGLES, verts);
}