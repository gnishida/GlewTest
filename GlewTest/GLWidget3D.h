/*********************************************************************
This file is part of QtUrban.

    QtUrban is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    QtUrban is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with QtUrban.  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************/

#pragma once

#include <GL/glew.h>

#include <QGLWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QVector2D>
#include "RenderManager.h"
#include "Camera.h"

class MainWindow;

using namespace std;

class GLWidget3D : public QGLWidget {
public:
	MainWindow* mainWin;
	RenderManager renderManager;
	Camera camera;

	bool shiftPressed;
	bool controlPressed;
	bool altPressed;

	QPoint lastPos;
	float rotationSensitivity;
	float zoomSensitivity;

public:
	GLWidget3D(MainWindow *parent);
	~GLWidget3D();

	QSize minimumSizeHint() const;
	QSize sizeHint() const;
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);


	void drawScene();

protected:
	void initializeGL();

	void resizeGL(int width, int height);
	void paintGL();    

	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);

private:
	void updateCamera();

};

