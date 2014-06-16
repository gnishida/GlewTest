#include "ShaderInterface.h"
#include <QFile>
#include <QTextStream>
#include <iostream>

uint ShaderInterface::initShader(const QString& vertFileName, const QString& fragFileName) {
	std::string source;
	loadTextFile(vertFileName,source);
	uint vs=loadShader(source, GL_VERTEX_SHADER);

	source="";
	loadTextFile(fragFileName,source);
	uint fs=loadShader(source,GL_FRAGMENT_SHADER);

	//create program
	int programId = glCreateProgram();
	glAttachShader(programId, vs);
	glAttachShader(programId, fs);
	glBindFragDataLocation(programId, 0, "outputF");
	glLinkProgram(programId);
	
	//check program
	{
		int infologLength = 0;
		glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infologLength);
		if (infologLength > 0){
			char* infoLog= (char*)malloc(infologLength);
			glGetProgramInfoLog(programId, infologLength, NULL, infoLog);
			printf("%s\n", infoLog);
			free(infoLog);
		}
	}

	return programId;
}

void ShaderInterface::loadTextFile(QString fileName,std::string& str){
	QFile file(fileName);
	if(!file.open(QIODevice::ReadOnly)) {
		printf("ERROR: loadTexFile: %s\n", file.errorString().toAscii().constData());
		//QMessageBox::information(0, "error", file.errorString());
	}

	QTextStream in(&file);
	QString text;
	while(!in.atEnd()) {
		QString line = in.readLine();    
		text+=line+"\n"; 
	}
	file.close();
	str=std::string(text.toAscii().constData());
}//

uint ShaderInterface::loadShader(std::string& source,uint mode){
	GLenum err;
	uint id=glCreateShader(mode);//GL_VERTEX_SHADER,GL_FRAGMENT_SHADER
	const char* csource=source.c_str();
	glShaderSource(id,1,&csource,NULL);
	glCompileShader(id);
	int infologLength = 0;
	glGetShaderiv(id, GL_INFO_LOG_LENGTH,&infologLength);
	if(infologLength>1){
		char *infoLog=(char *)malloc(infologLength);
		glGetShaderInfoLog(id,1000,NULL,infoLog);
		printf("Compile status %d:\n %s\n",infologLength,infoLog);
		free(infoLog);
		exit(1);
	}else{
		printf("Compile status: OK\n");
	}
	//while ((err = glGetError()) != GL_NO_ERROR) qDebug() << "*loadShader ERROR INIT: OpenGL-->" << err << endl;
	return id;
}//