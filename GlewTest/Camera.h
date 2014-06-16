#pragma once

#include <GL/glew.h>

#include <QVector4D>
#include <QMatrix4x4>

#define M_PI 3.141592653589

class Camera {
public:
	float xrot;
	float yrot;
	float zrot;

	QVector3D pos;
	QVector3D lookAt;

	float fov;

	QMatrix4x4 viewM;
	QMatrix4x4 projM;

	Camera() {
		xrot = 0.0f;//-75.0;
		yrot = 0.0;
		zrot = 0.0f;//-45.0;

		//pos = QVector3D(10, 2, 10);
		pos = QVector3D(0, 2, 20);
		lookAt = QVector3D(0, 0, 0);

		fov = 53.13f;
	}

	QVector4D getCamPos() {
		QVector4D eye(0.0f, 0.0f, 0.0f, 1.0f);
		return ((viewM.transposed()).inverted())*eye;
	}

	void updatePerspective(int width,int height){
		if (height == 0) height = 1;
		float ratio = (float)width / (float)height;

		buildProjectionMatrix(fov, ratio, 1.0f, 3000.0f);
	}

	void buildProjectionMatrix(float fov, float ratio, float nearP, float farP) {
		float f = 1.0f / tan (fov * (M_PI / 360.0));
 
		projM.setColumn(0, QVector4D(f/ratio, 0, 0, 0));
		projM.setColumn(1, QVector4D(0, f, 0, 0));
		projM.setColumn(2, QVector4D(0, 0, (farP + nearP) / (nearP - farP), -1));
		projM.setColumn(3, QVector4D(0, 0, (2.0f * farP * nearP) / (nearP - farP), 0));
	}

	void updateCamMatrix() {
		// modelview matrix
		viewM.setToIdentity();
		viewM.translate(-pos.x(), -pos.y(), -pos.z());
		viewM.rotate(xrot, 1.0, 0.0, 0.0);		
		viewM.rotate(yrot, 0.0, 1.0, 0.0);
		viewM.rotate(zrot, 0.0, 0.0, 1.0);
		viewM.translate(-lookAt.x(), -lookAt.y(), -lookAt.z());

		/*
		QVector3D up(0, 1, 0);
 
		QVector3D dir = (lookAt - pos).normalized();
		QVector3D right = QVector3D::crossProduct(dir, up);
		right.normalize();

		up = QVector3D::crossProduct(right, dir);
		up.normalize();
 
		viewM.setRow(0, QVector4D(right));
		viewM.setRow(1, QVector4D(up));
		viewM.setRow(2, QVector4D(-dir));
		viewM.setRow(3, QVector4D(0, 0, 0, 1));

		viewM.translate(-pos.x(), -pos.y(), -pos.z());
		*/
	}

	static void qNormalizeAngle(float &angle) {
		while (angle < 0)
			angle += 360.0;
		while (angle >= 360.0)
			angle -= 360.0;
	}

	float getCamElevation() {	
		return getCamPos().z();
	}

	void setRotation(float x, float y, float z) {
		setXRotation(x);
		setYRotation(y);
		setZRotation(z);		
	}

	void setXRotation(float angle) {
		qNormalizeAngle(angle);
		xrot = angle;			
	}

	void setYRotation(float angle) {
		qNormalizeAngle(angle);
		yrot = angle;			
	}

	void setZRotation(float angle) {
		qNormalizeAngle(angle);
		zrot = angle;			
	}

	void changeXRotation(float angle) {
		setXRotation(xrot+angle);
	}

	void changeYRotation(float angle) {
		setYRotation(yrot+angle);
	}

	void changeZRotation(float angle) {
		setZRotation(zrot+angle);
	}

	void setTranslation(float x, float y, float z) {
		pos = QVector3D(x, y, z);
	}

	void changeXYZTranslation(float x, float y, float z) {
		pos.setX(pos.x() + x);
		pos.setY(pos.y() + y);
		pos.setZ(pos.z() + z);
	}

	void setLookAt(float x, float y, float z) {
		lookAt = QVector3D(x, y, z);
	}

	void resetCamera(){
		setLookAt(0.0f, 0.0f, 0.0f);
		setTranslation(0.0f, 0.0f, 100.0f);
	}
};

