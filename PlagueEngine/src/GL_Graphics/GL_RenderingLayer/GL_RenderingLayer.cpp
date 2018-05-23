#include "GL_RenderingLayer.h"

void GL_RenderingLayer::init()
{
	Shader = new GL_Shader;
	Renderer = new GL_Renderer;
}

GL_RenderingLayer::~GL_RenderingLayer()
{
	delete Shader;
	delete Renderer;
}