#pragma once

#include <iostream>
#include <string>
#include "SDL.h"
#include "glew.h"

class GL_Window
{

private:	// OBJECTS

	SDL_Window *window;
	SDL_GLContext glcontext;

public:		// METHODS

	void setSDLAttribute(SDL_GLattr attr, int value);
	bool init(const char *title, int width, int height, Uint32 flags);
	void setVsync(bool v_sync);
	void update();

	~GL_Window();

private:	// METHODS

	bool initSDL();
	bool createContext();
	bool initGLEW();

};


