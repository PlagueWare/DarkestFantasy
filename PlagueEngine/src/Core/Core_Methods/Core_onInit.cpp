#include "Core.h"
#include "glm.hpp"
#include "ext.hpp"

bool Core::onInit()
{
	// WINDOW SETUP //
	Window.setSDLAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	Window.setSDLAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	Window.setSDLAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	Window.setSDLAttribute(SDL_GL_DOUBLEBUFFER, 1);
	Window.setSDLAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	Window.setSDLAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);
	Window.setSDLAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	Window.setSDLAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	Window.init("PlagueEngine", 1366, 768, SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE);
	Window.setVsync(false);

	// SCENE LAYER SETUP //
	SceneLayer.init();
	SceneLayer.Shader->link("basicVert.glsl", GL_VERTEX_SHADER);
	SceneLayer.Shader->link("basicFrag.glsl", GL_FRAGMENT_SHADER);
	SceneLayer.Shader->enable();
	SceneLayer.Renderer->init(GL_DYNAMIC_DRAW);

	return true;
}
