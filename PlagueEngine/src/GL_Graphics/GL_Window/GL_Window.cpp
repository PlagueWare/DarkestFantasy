#include "GL_Window.h"

GL_Window::~GL_Window()
{
	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GL_Window::setSDLAttribute(SDL_GLattr attr, int value)
{
	SDL_GL_SetAttribute(attr, value);
}

bool GL_Window::init(const char *title, int width, int height, Uint32 flags)
{
	initSDL();

	// Create an application window with the following settings:
	window = SDL_CreateWindow
	(
		title,								// window title
		SDL_WINDOWPOS_CENTERED,				// initial x position
		SDL_WINDOWPOS_CENTERED,				// initial y position
		width,								// width, in pixels
		height,								// height, in pixels
		SDL_WINDOW_OPENGL | flags
	);

	createContext();
	initGLEW();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	return true;
}

void GL_Window::setVsync(bool v_sync)
{
	SDL_GL_SetSwapInterval(v_sync);
}

void GL_Window::update()
{
	SDL_GL_SwapWindow(window);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
		std::cout << "OpenGL error: " << error << std::endl;
}

// PRIVATE METHODS

bool GL_Window::initSDL()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
	{
		return true;
	}

	
}

bool GL_Window::createContext()
{
	glcontext = SDL_GL_CreateContext(window);
	if (!glcontext)
	{
		fprintf(stderr, "Couldn't create context: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
		std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
		return true;
	}
}

bool GL_Window::initGLEW()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW failed to initialize. Error: %s\n", glewGetErrorString(err));
		return false;
	}
	else
	{
		fprintf(stdout, "GLEW version: %s\n", glewGetString(GLEW_VERSION));
		return true;
	}
}
