#include "GL_Buffers.h"

GL_DataBuffer::GL_DataBuffer()
{
	glGenBuffers(1, &m_DataBufferID);
	bind();
}

GL_DataBuffer::~GL_DataBuffer()
{
	unbind();
	glDeleteBuffers(1, &m_DataBufferID);
}

void GL_DataBuffer::bufferData(GLenum target, GLsizeiptr size, const void* data,  GLenum glDynamicOrStaticDraw)
{
	bind();
	glBufferData(target, size, data, glDynamicOrStaticDraw);
}

void GL_DataBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_DataBufferID);
}

void GL_DataBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}



GL_IndexBuffer::GL_IndexBuffer()
{
	glGenBuffers(1, &m_IndexBufferID);
	bind();
}

GL_IndexBuffer::~GL_IndexBuffer()
{
	unbind();
	glDeleteBuffers(1, &m_IndexBufferID);
}

void GL_IndexBuffer::bufferData(GLenum target, GLsizeiptr size, const void* data, GLenum glDynamicOrStaticDraw)
{
	bind();
	glBufferData(target, size, data, glDynamicOrStaticDraw);
}

void GL_IndexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
}

void GL_IndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}



GL_BufferArray::GL_BufferArray()
{
	glGenVertexArrays(1, &m_BufferArrayID);
	bind();
}

GL_BufferArray::~GL_BufferArray()
{
	unbind();
	glDeleteVertexArrays(1, &m_BufferArrayID);
}

void GL_BufferArray::pushVertexAttrib(GLuint shaderLayoutIndex, GLenum glVarType, GLenum glNormalized, GLsizei glStride, const void* offset)
{
	glEnableVertexAttribArray(shaderLayoutIndex);
	glVertexAttribPointer(shaderLayoutIndex, 4, glVarType, glNormalized, glStride, offset);
}

void GL_BufferArray::bind()
{
	glBindVertexArray(m_BufferArrayID);
}

void GL_BufferArray::unbind()
{
	glBindVertexArray(0);
}