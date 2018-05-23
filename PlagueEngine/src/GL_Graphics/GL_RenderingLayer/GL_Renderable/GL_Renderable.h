#pragma once

#include "GLM_MVP_Matrices.h"

struct VertexData
{
	glm::vec4 vertex;
	glm::vec4 color;
};

class GL_Renderable
{

public:

	glm::vec3 Scale;
	glm::vec3 Position;
	glm::vec4 Color;

public:

	GL_Renderable(glm::vec3 scale, glm::vec3 position, glm::vec4 color);

};