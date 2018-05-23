#pragma once

#include <string>
#include "glew.h"
#include "glm.hpp"

class GL_Shader
{

private:	// OBJECTS

	GLuint m_ShaderProgramID;

private:	// VARIABLES

	std::string m_FolderPath = "src/GL_Graphics/GL_RenderingLayer/GL_Shader/GLSL_Shaders/";

public:		// METHODS

	void link(std::string shaderFile, GLenum glShaderType);
	void enable();
	void setUniform1i(const GLchar* name, int value);
	void setUniform1f(const GLchar* name, float value);
	void setUniform2f(const GLchar* name, const glm::vec2& vector);
	void setUniform3f(const GLchar* name, const glm::vec3& vector);
	void setUniform4f(const GLchar* name, const glm::vec4& vector);
	void setUniformMat4(const GLchar* name, const glm::mat4& matrix);

	GL_Shader();
	~GL_Shader();

private:	// METHODS

	GLint getUniformLocation(const GLchar* name);

};
