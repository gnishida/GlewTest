#include "GLWidget3D.h"
#include "MainWindow.h"
#include <QVector2D>
#include <iostream>

GLWidget3D::GLWidget3D(MainWindow* mainWin) : QGLWidget(QGLFormat(QGL::SampleBuffers), (QWidget*)mainWin) {
	this->mainWin = mainWin;

	controlPressed=false;
	shiftPressed=false;
	altPressed=false;

	rotationSensitivity = 0.4f;
	zoomSensitivity = 10.0f;
}

GLWidget3D::~GLWidget3D() {
}

QSize GLWidget3D::minimumSizeHint() const {
	return QSize(200, 200);
}

QSize GLWidget3D::sizeHint() const {
	return QSize(400, 400);
}

void GLWidget3D::mousePressEvent(QMouseEvent *event) {
	QVector2D pos;

	this->setFocus();

	lastPos = event->pos();
	//mouseTo2D(event->x(), event->y(), pos);

	if (event->buttons() & Qt::LeftButton) {
	}
}

void GLWidget3D::mouseReleaseEvent(QMouseEvent *event) {
	event->ignore();

	updateGL();

	return;
}

void GLWidget3D::mouseMoveEvent(QMouseEvent *event) {
	QVector2D pos;
	//mouseTo2D(event->x(), event->y(), pos);

	float dx = (float)(event->x() - lastPos.x());
	float dy = (float)(event->y() - lastPos.y());

	lastPos = event->pos();
	
	if (event->buttons() & Qt::LeftButton) {	// Rotate
		camera.changeXRotation(rotationSensitivity * dy);
		camera.changeZRotation(-rotationSensitivity * dx);    
		updateCamera();
		lastPos = event->pos();
	} else if (event->buttons() & Qt::MidButton) {
		camera.changeXYZTranslation(-dx, dy, 0);
		updateCamera();
		lastPos = event->pos();
	} else if (event->buttons() & Qt::RightButton) {	// Zoom
		camera.changeXYZTranslation(0, 0, -zoomSensitivity * dy);
		updateCamera();
		lastPos = event->pos();
	}

	updateGL();
}

void GLWidget3D::initializeGL() {
    glewInit();
    if (glewIsSupported("GL_VERSION_3_3"))
        printf("Ready for OpenGL 3.3\n");
    else {
        printf("OpenGL 3.3 not supported\n");
        exit(1);
    }

	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);

	glDepthFunc(GL_LEQUAL);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPointSize(10.0f);

	renderManager.init();
	renderManager.setup();
	updateCamera();
}

void GLWidget3D::resizeGL(int width, int height) {
	updateCamera();
}

void GLWidget3D::paintGL() {
	
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);
	//glDisable(GL_TEXTURE_2D);
	
	// NOTE: camera transformation is not necessary here since the updateCamera updates the uniforms each time they are changed

	drawScene();		
}

void GLWidget3D::drawScene() {
	renderManager.render();
}

void GLWidget3D::keyPressEvent( QKeyEvent *e ){
	shiftPressed=false;
	controlPressed=false;
	altPressed=false;

	switch( e->key() ){
	case Qt::Key_Shift:
		shiftPressed=true;
		break;
	case Qt::Key_Control:
		controlPressed=true;
		break;
	case Qt::Key_Alt:
		altPressed=true;
		break;
	case Qt::Key_Escape:
		break;
	case Qt::Key_R:
		break;
	case Qt::Key_W:
		break;
	case Qt::Key_S:
		break;
	case Qt::Key_D:
		break;
	case Qt::Key_A:
		break;
	case Qt::Key_Q:
		break;
	default:
		;
	}
}

void GLWidget3D::keyReleaseEvent(QKeyEvent* e) {
	if (e->isAutoRepeat()) {
		e->ignore();
		return;
	}
	switch (e->key()) {
	case Qt::Key_Shift:
		shiftPressed=false;
		break;
	case Qt::Key_Control:
		controlPressed=false;
		break;
	case Qt::Key_Alt:
		altPressed=false;
	default:
		;
	}
}

void GLWidget3D::updateCamera() {
	glViewport(0, 0, this->width(), this->height());
	camera.updatePerspective(this->width(), this->height());
	camera.updateCamMatrix();

	float viewMatrix[16];
	float projMatrix[16];

	for (int i = 0; i < 16; i++) {
		viewMatrix[i] = camera.viewM.data()[i];
		projMatrix[i] = camera.projM.data()[i];
	}

    // must be called after glUseProgram
    glUniformMatrix4fv(glGetUniformLocation(renderManager.program, "projMatrix"),  1, false, projMatrix);
    glUniformMatrix4fv(glGetUniformLocation(renderManager.program, "viewMatrix"),  1, false, viewMatrix);
}