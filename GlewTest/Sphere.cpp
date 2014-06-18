#include "Sphere.h"

#ifndef M_PI
#define M_PI 3.141592653589
#endif

Sphere::Sphere(float radius, const QColor& color, int slice, int stack) {
	Vertex v;
	v.color[0] = color.redF(); v.color[1] = color.greenF(); v.color[2] = color.blueF();

	for (int i = 0; i < slice; ++i) {
		float theta1 = M_PI * 2.0f * (float)i / (float)slice;
		float theta2 = M_PI * 2.0f * (float)(i + 1) / (float)slice;

		for (int j = 0; j < stack; ++j) {
			float rho1 = M_PI * (float)j / (float)stack - M_PI * 0.5f;
			float rho2 = M_PI * (float)(j + 1) / (float)stack - M_PI * 0.5f;

			v.location[0] = cosf(theta1) * cosf(rho1) * radius; v.location[1] = sinf(theta1) * cosf(rho1) * radius; v.location[2] = sinf(rho1) * radius;
			v.normal[0] = cosf(theta1) * cosf(rho1) * radius; v.normal[1] = sinf(theta1) * cosf(rho1) * radius; v.normal[2] = sinf(rho1) * radius;
			verts.push_back(v);

			v.location[0] = cosf(theta2) * cosf(rho1) * radius; v.location[1] = sinf(theta2) * cosf(rho1) * radius; v.location[2] = sinf(rho1) * radius;
			v.normal[0] = cosf(theta2) * cosf(rho1) * radius; v.normal[1] = sinf(theta2) * cosf(rho1) * radius; v.normal[2] = sinf(rho1) * radius;
			verts.push_back(v);

			v.location[0] = cosf(theta2) * cosf(rho2) * radius; v.location[1] = sinf(theta2) * cosf(rho2) * radius; v.location[2] = sinf(rho2) * radius;
			v.normal[0] = cosf(theta2) * cosf(rho2) * radius; v.normal[1] = sinf(theta2) * cosf(rho2) * radius; v.normal[2] = sinf(rho2) * radius;
			verts.push_back(v);


			v.location[0] = cosf(theta1) * cosf(rho1) * radius; v.location[1] = sinf(theta1) * cosf(rho1) * radius; v.location[2] = sinf(rho1) * radius;
			v.normal[0] = cosf(theta1) * cosf(rho1) * radius; v.normal[1] = sinf(theta1) * cosf(rho1) * radius; v.normal[2] = sinf(rho1) * radius;
			verts.push_back(v);

			v.location[0] = cosf(theta2) * cosf(rho2) * radius; v.location[1] = sinf(theta2) * cosf(rho2) * radius; v.location[2] = sinf(rho2) * radius;
			v.normal[0] = cosf(theta2) * cosf(rho2) * radius; v.normal[1] = sinf(theta2) * cosf(rho2) * radius; v.normal[2] = sinf(rho2) * radius;
			verts.push_back(v);

			v.location[0] = cosf(theta1) * cosf(rho2) * radius; v.location[1] = sinf(theta1) * cosf(rho2) * radius; v.location[2] = sinf(rho2) * radius;
			v.normal[0] = cosf(theta1) * cosf(rho2) * radius; v.normal[1] = sinf(theta1) * cosf(rho2) * radius; v.normal[2] = sinf(rho2) * radius;
			verts.push_back(v);
		}
	}
}

void Sphere::translate(float dx, float dy, float dz) {
	for (int i = 0; i < verts.size(); ++i) {
		verts[i].location[0] += dx;
		verts[i].location[1] += dy;
		verts[i].location[2] += dz;
	}
}
