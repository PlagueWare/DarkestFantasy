#include "Core.h"

Core::Core()
{
	m_Running = true;
}

int Core::onExecute()
{
	if (onInit() == false)
	{
		return -1;
	}

	SDL_Event Event;

	while (m_Running)
	{
		while (SDL_PollEvent(&Event))
		{
			onEvent(&Event);
		}

		onLoop();

		onRender();
	}

	onCleanup();

	return 0;
}