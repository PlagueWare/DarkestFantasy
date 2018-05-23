#include "GL_Renderer.h"

void GL_Renderer::init(GLenum glDynamicOrStaticDraw)
{
	GLuint* indices = new GLuint[MAX_INDICES];	

	for (int i = 0, o = 0; i < MAX_INDICES; i += 36, o += 8)
	{
		// FRONT
		indices[i +  0] = o + 0;
		indices[i +  1] = o + 1;
		indices[i +  2] = o + 2;
		indices[i +  3] = o + 2;
		indices[i +  4] = o + 3;
		indices[i +  5] = o + 0;
							
		// BACK   			   
		indices[i +  6] = o + 5;
		indices[i +  7] = o + 4;
		indices[i +  8] = o + 7;
		indices[i +  9] = o + 7;
		indices[i + 10] = o + 6;
		indices[i + 11] = o + 5;

		// LEFT
		indices[i + 12] = o + 4;
		indices[i + 13] = o + 0;
		indices[i + 14] = o + 3;
		indices[i + 15] = o + 3;
		indices[i + 16] = o + 7;
		indices[i + 17] = o + 4;

		// RIGHT
		indices[i + 18] = o + 1;
		indices[i + 19] = o + 5;
		indices[i + 20] = o + 6;
		indices[i + 21] = o + 6;
		indices[i + 22] = o + 2;
		indices[i + 23] = o + 1;

		// TOP
		indices[i + 24] = o + 4;
		indices[i + 25] = o + 5;
		indices[i + 26] = o + 1;
		indices[i + 27] = o + 1;
		indices[i + 28] = o + 0;
		indices[i + 29] = o + 4;

		// BOTTOM
		indices[i + 30] = o + 3;
		indices[i + 31] = o + 2;
		indices[i + 32] = o + 6;
		indices[i + 33] = o + 6;
		indices[i + 34] = o + 7;
		indices[i + 35] = o + 3;
	}

	m_IndexBuffer.bufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_INDICES * sizeof(GLuint), indices, glDynamicOrStaticDraw);
	m_DataBuffer.bufferData(GL_ARRAY_BUFFER, MAX_VERTICES * sizeof(VertexData), NULL, glDynamicOrStaticDraw);
	m_BufferArray.pushVertexAttrib(0, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const GLvoid*) 0);
	m_BufferArray.pushVertexAttrib(1, GL_FLOAT, GL_FALSE, sizeof(VertexData), (const GLvoid*)(offsetof(VertexData, VertexData::color)));
}

void GL_Renderer::clear(float r, float g, float b, float a)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(r, g, b, a);

	pushMatrix(glm::mat4(1.0f), true);
}

void GL_Renderer::begin()
{
	m_BufferMap = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void GL_Renderer::submit(GL_Renderable renderable)
{
	glm::vec3 pos = renderable.Position;
	glm::vec3 scl = renderable.Scale;
	glm::vec4 col = renderable.Color;

	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x - scl.x, pos.y + scl.y, pos.z + scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;
	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x + scl.x, pos.y + scl.y, pos.z + scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;
	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x + scl.x, pos.y - scl.y, pos.z + scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;
	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x - scl.x, pos.y - scl.y, pos.z + scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;
	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x - scl.x, pos.y + scl.y, pos.z - scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;
	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x + scl.x, pos.y + scl.y, pos.z - scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;
	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x + scl.x, pos.y - scl.y, pos.z - scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;
	m_BufferMap->vertex = m_MatrixStack.back() * glm::vec4(pos.x - scl.x, pos.y - scl.y, pos.z - scl.z, 1.0f);
	m_BufferMap->color = col;
	m_BufferMap++;

	m_IndexCount += 36;
}

void GL_Renderer::end()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
}

void GL_Renderer::draw(GLenum glDrawMode)
{
	glDrawElements(glDrawMode, m_IndexCount, GL_UNSIGNED_INT, NULL);
}

void GL_Renderer::pushMatrix(glm::mat4 matrix, bool override)
{
	if (override)
		m_MatrixStack.push_back(matrix);
	else
		m_MatrixStack.push_back(m_MatrixStack.back() * matrix);
}

void GL_Renderer::popMatrix()
{
	if (m_MatrixStack.size() > 1)
		m_MatrixStack.pop_back();
}

