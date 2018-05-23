#pragma once

#include "SDL.h"

class CoreEvent
{

public:		// METHODS

	CoreEvent()
	{

	}

	virtual ~CoreEvent()
	{

	}

	virtual void OnEvent(SDL_Event* Event)
	{
		switch (Event->type)
		{
			case SDL_KEYDOWN:
			{
			switch (Event->key.keysym.sym)
			{
				case SDLK_a:
				{
				break;
			}

				case SDLK_b:
				{
				break;
			}

				case SDLK_c:
				{
				break;
			}

				case SDLK_d:
				{
				break;
			}

				case SDLK_e:
				{
				break;
			}

				case SDLK_f:
				{
				break;
			}

				case SDLK_g:
				{
				break;
			}

				case SDLK_h:
				{
				break;
			}

				case SDLK_i:
				{
				break;
			}

				case SDLK_j:
				{
				break;
			}

				case SDLK_k:
				{
				break;
			}

				case SDLK_l:
				{
				break;
			}

				case SDLK_m:
				{
				break;
			}

				case SDLK_n:
				{
				break;
			}

				case SDLK_o:
				{
				break;
			}

				case SDLK_p:
				{
				break;
			}

				case SDLK_q:
				{
				break;
			}

				case SDLK_r:
				{
				break;
			}

				case SDLK_s:
				{
				break;
			}

				case SDLK_t:
				{
				break;
			}

				case SDLK_u:
				{
				break;
			}

				case SDLK_v:
				{
				break;
			}

				case SDLK_w:
				{
				break;
			}

				case SDLK_x:
				{
				break;
			}

				case SDLK_y:
				{
				break;
			}

				case SDLK_z:
				{
				break;
			}

				case SDLK_ESCAPE:
				{
				OnExit();
				break;
			}
			}
		}

			case SDL_MOUSEMOTION:
			{
			OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
		}

			case SDL_MOUSEBUTTONDOWN:
			{
			switch (Event->button.button)
			{
				case SDL_BUTTON_LEFT:
				{
				OnLButtonDown(Event->button.x, Event->button.y);
				break;
			}
				case SDL_BUTTON_RIGHT:
				{
				OnRButtonDown(Event->button.x, Event->button.y);
				break;
			}
				case SDL_BUTTON_MIDDLE:
				{
				OnMButtonDown(Event->button.x, Event->button.y);
				break;
			}
			}
			break;
		}

			case SDL_MOUSEBUTTONUP:
			{
			switch (Event->button.button)
			{
				case SDL_BUTTON_LEFT:
				{
				OnLButtonUp(Event->button.x, Event->button.y);
				break;
			}

				case SDL_BUTTON_RIGHT:
				{
				OnRButtonUp(Event->button.x, Event->button.y);
				break;
			}

				case SDL_BUTTON_MIDDLE:
				{
				OnMButtonUp(Event->button.x, Event->button.y);
				break;
			}
			}
			break;
		}

			case SDL_JOYAXISMOTION:
			{
			OnJoyAxis(Event->jaxis.which, Event->jaxis.axis, Event->jaxis.value);
			break;
		}

			case SDL_JOYBALLMOTION:
			{
			OnJoyBall(Event->jball.which, Event->jball.ball, Event->jball.xrel, Event->jball.yrel);
			break;
		}

			case SDL_JOYHATMOTION:
			{
			OnJoyHat(Event->jhat.which, Event->jhat.hat, Event->jhat.value);
			break;
		}

			case SDL_JOYBUTTONDOWN:
			{
			OnJoyButtonDown(Event->jbutton.which, Event->jbutton.button);
			break;
		}

			case SDL_JOYBUTTONUP:
			{
			OnJoyButtonUp(Event->jbutton.which, Event->jbutton.button);
			break;
		}

			case SDL_QUIT:
			{
				OnExit();
				break;
			}

			case SDL_SYSWMEVENT:
			{
			break;
		}

			case SDL_WINDOWEVENT:
			{
				switch (Event->window.event)
				{
					case SDL_WINDOWEVENT_SHOWN:
					{
				SDL_Log("Window %d shown", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_HIDDEN:
					{
				SDL_Log("Window %d hidden", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_EXPOSED:
					{
				SDL_Log("Window %d exposed", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_MOVED:
					{
				SDL_Log("Window %d moved to %d,%d", Event->window.windowID, Event->window.data1, Event->window.data2);
				break;
			}

					case SDL_WINDOWEVENT_RESIZED:
					{
				SDL_Log("Window %d resized to %dx%d", Event->window.windowID, Event->window.data1, Event->window.data2);
				break;
			}

					case SDL_WINDOWEVENT_SIZE_CHANGED:
					{
				SDL_Log("Window %d size changed to %dx%d", Event->window.windowID, Event->window.data1, Event->window.data2);
				break;
			}

					case SDL_WINDOWEVENT_MINIMIZED:
					{
				SDL_Log("Window %d minimized", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_MAXIMIZED:
					{
				SDL_Log("Window %d maximized", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_RESTORED:
					{
				SDL_Log("Window %d restored", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_ENTER:
					{
				SDL_Log("Mouse entered window %d", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_LEAVE:
					{
				SDL_Log("Mouse left window %d", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_FOCUS_GAINED:
					{
				SDL_Log("Window %d gained keyboard focus", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_FOCUS_LOST:
					{
				SDL_Log("Window %d lost keyboard focus", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_CLOSE:
					{
				SDL_Log("Window %d closed", Event->window.windowID);
				break;
			}

#if SDL_VERSION_ATLEAST(2, 0, 5)

					case SDL_WINDOWEVENT_TAKE_FOCUS:
					{
				SDL_Log("Window %d is offered a focus", Event->window.windowID);
				break;
			}

					case SDL_WINDOWEVENT_HIT_TEST:
					{
				SDL_Log("Window %d has a special hit test", Event->window.windowID);
				break;
			}

#endif

					default:
					{
					SDL_Log("Window %d got unknown event %d", Event->window.windowID, Event->window.event);
					break;
				}
				}
			}

			default:
			{
			OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
			break;
		}
		}
	}

	virtual void OnInputFocus()
	{

	}

	virtual void OnInputBlur()
	{

	}

	virtual void OnMouseFocus()
	{

	}

	virtual void OnMouseBlur()
	{

	}

	virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle)
	{

	}

	virtual void OnMouseWheel(bool Up, bool Down)
	{

	}

	virtual void OnLButtonDown(int mX, int mY)
	{

	}

	virtual void OnLButtonUp(int mX, int mY)
	{

	}

	virtual void OnRButtonDown(int mX, int mY)
	{

	}

	virtual void OnRButtonUp(int mX, int mY)
	{

	}

	virtual void OnMButtonDown(int mX, int mY)
	{

	}

	virtual void OnMButtonUp(int mX, int mY)
	{

	}

	virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
	{

	}

	virtual void OnJoyButtonDown(Uint8 which, Uint8 button)
	{

	}

	virtual void OnJoyButtonUp(Uint8 which, Uint8 button)
	{

	}

	virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value)
	{

	}

	virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
	{

	}

	virtual void OnMinimize()
	{

	}

	virtual void OnRestore()
	{

	}

	virtual void OnResize(int w, int h)
	{

	}

	virtual void OnExpose()
	{

	}

	virtual void OnExit()
	{

	}

	virtual void OnUser(Uint8 type, int code, void* data1, void* data2)
	{

	}

};