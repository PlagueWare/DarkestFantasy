#pragma once

#include "Core_Event.h"
#include "GL_Window.h"
#include "GL_RenderingLayer.h"

class Core : public CoreEvent
{
public:		// GLOBAL OBJECTS

	GL_Window Window;
	GL_RenderingLayer SceneLayer;

private:	// CORE VARIABLES

	bool m_Running;

public:		// CORE METHODS

	Core();
	
	int onExecute();	
	bool onInit();
	void onEvent(SDL_Event* Event);
	void onLoop();
	void onRender();
	void onCleanup();
	void OnExit();

};
