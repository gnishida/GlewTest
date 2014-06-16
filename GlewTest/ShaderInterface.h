#pragma once

#include <GL/glew.h>
#include <QString>

class ShaderInterface {
private:
	GLuint program;

public:
	ShaderInterface() {}

	static uint initShader(const QString& vertFileName, const QString& fragFileName);
	static void loadTextFile(QString fileName,std::string& str);
	static uint loadShader(std::string& source,uint mode);
};

