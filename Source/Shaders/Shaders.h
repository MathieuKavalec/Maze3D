#pragma once

#include <iostream>
#include "glew.h"

#define OUTPUT_SHADER_COMPILE_LOG true

#define DEFAULT_FRAGMENT_SHADER	"Shaders/generic-fs.glsl"
#define DEFAULT_VERTEX_SHADER	"Shaders/generic-vs.glsl"

class Shader
{
public:
	Shader();
	Shader(const char* vertexShaderFileName, const char *fragmentShaderFileName);
	~Shader();

	GLuint CompileShader() const;

private:
	char* readTextFile(char* fileName);

	char* fragmentShader;
	char* vertexShader;
};


