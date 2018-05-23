#pragma once

#include <vector>
#include "GL_Buffers.h"
#include "GL_Renderable.h"

#define CHUNK_SIZE			128
#define MAX_RENDERABLES		CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE
#define MAX_VERTICES		MAX_RENDERABLES * 8
#define MAX_INDICES			MAX_RENDERABLES * 36

class GL_Renderer
{

private:	// OBJECTS

	GL_BufferArray	m_BufferArray;
	GL_IndexBuffer	m_IndexBuffer;
	GL_DataBuffer	m_DataBuffer;
	VertexData*		m_BufferMap;

	std::vector<glm::mat4> m_MatrixStack;

private:	// VARIABLES

	GLuint m_IndexCount;

public:		// METHODS

	void init(GLenum glDynamicOrStaticDraw);
	void clear(float r, float g, float b, float a);
	void begin();
	void submit(GL_Renderable renderable);
	void end();
	void draw(GLenum glDrawMode);

	void GL_Renderer::pushMatrix(glm::mat4 matrix, bool override = false);
	void GL_Renderer::popMatrix();

};