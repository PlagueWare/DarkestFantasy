#include "GL_Shader.h"

#include <iostream>
#include <string>
#include <vector>
#include "FileUtils.h"

void GL_Shader::link(std::string shaderFile, GLenum glShaderType)
{
	// Creates GL shader
	GLuint shader = glCreateShader(glShaderType);

	// Stores shader filepath in a const char pointer and returns it as a string
	std::string SourceString = FileUtils::read_file(m_FolderPath + shaderFile);
	const char* Source = SourceString.c_str();

	// Specify Shader source, number, filepath , and flags
	glShaderSource(shader, 1, &Source, NULL);
	glCompileShader(shader);

	// Gets compile status of shader and stores it in GLint "vresult"
	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	// If shader fails to compile, output errors to console
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(shader, length, &length, &error[0]);
		glDeleteShader(shader);
		std::cout << "SHADER FAILED TO COMPILE: " << shaderFile << std::endl;
		std::cout << "SHADER ERROR: " << &error << std::endl;
	}
	else
	{
		std::cout << "SHADER COMPILED: " << shaderFile << std::endl;
	}

	// Attach shaders to program
	glAttachShader(m_ShaderProgramID, shader);
	glDeleteShader(shader);
}

void GL_Shader::enable()
{
	glLinkProgram(m_ShaderProgramID);
	glValidateProgram(m_ShaderProgramID);
	glUseProgram(m_ShaderProgramID);
}

void GL_Shader::setUniform1i(const GLchar* name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void GL_Shader::setUniform1f(const GLchar* name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}

void GL_Shader::setUniform2f(const GLchar* name, const glm::vec2& vector)
{
	glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void GL_Shader::setUniform3f(const GLchar* name, const glm::vec3& vector)
{
	glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}

void GL_Shader::setUniform4f(const GLchar* name, const glm::vec4& vector)
{
	glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}

void GL_Shader::setUniformMat4(const GLchar* name, const glm::mat4& matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

GL_Shader::GL_Shader()
{
	// Creates a shader program called "program"
	m_ShaderProgramID = glCreateProgram();
	std::cout << "SHADER PROGRAM " << m_ShaderProgramID << " CREATED." << std::endl;
}

GL_Shader::~GL_Shader()
{
	glDeleteProgram(m_ShaderProgramID);
	std::cout << "SHADER PROGRAM " << m_ShaderProgramID << " DESTROYED." << std::endl;
}

// PRIVATE METHODS

GLint GL_Shader::getUniformLocation(const GLchar* name)
{
	return glGetUniformLocation(m_ShaderProgramID, name);
}