#pragma once

#include "GL_Shader.h"
#include "GL_Renderer.h"

class GL_RenderingLayer
{

public:	// OBJECTS

	GL_Shader* Shader;
	GL_Renderer* Renderer;

public:		// METHODS

	void init();

	~GL_RenderingLayer();
};