#pragma once

#include <iostream>
#include "glew.h"
#include "glm.hpp"

class GL_DataBuffer
{

private:	// OBJECTS

	GLuint m_DataBufferID;

public:		// METHODS

	GL_DataBuffer();
	~GL_DataBuffer();

	void bufferData(GLenum target, GLsizeiptr size, const void* data, GLenum glDynamicOrStaticDraw);
	void bind();
	void unbind();
};

class GL_IndexBuffer
{

private:	// OBJECTS

	GLuint m_IndexBufferID;

public:		// METHODS

	GL_IndexBuffer();
	~GL_IndexBuffer();

	void bufferData(GLenum target, GLsizeiptr size, const void* data, GLenum glDynamicOrStaticDraw);
	void bind();
	void unbind();
};

class GL_BufferArray
{

private:	// OBJECTS

	GLuint m_BufferArrayID;

public:		// METHODS

	GL_BufferArray();
	~GL_BufferArray();

	void pushVertexAttrib(GLuint shaderLayoutIndex, GLenum glVarType, GLenum glNormalized, GLsizei glStride, const void* offset);
	void bind();
	void unbind();

};