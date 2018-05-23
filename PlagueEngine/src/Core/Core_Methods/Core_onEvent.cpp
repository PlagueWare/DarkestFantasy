#include "Core.h"

void Core::onEvent(SDL_Event* Event)
{
	CoreEvent::OnEvent(Event);
}

void Core::OnExit()
{
	m_Running = false;
}