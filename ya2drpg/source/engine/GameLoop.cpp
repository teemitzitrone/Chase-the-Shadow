#include "GameLoop.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include <time.h>

#define FRAMES_PER_SECOND 60.0
#define MILLISECONDS_PER_FRAME 1000.0 / FRAMES_PER_SECOND

GameLoop::GameLoop(SDL_Renderer* renderer, GameObjectManager* gameObjectManager) :
	_done(false),
	_renderer(renderer),
	_manager(gameObjectManager)
{
}

GameLoop::~GameLoop(void)
{
}

/// <summary>
/// Run Method for GameLoop
/// </summary>
///
/// <remarks>
/// Puts up a loop to run at a defined number of frames per second. 
/// The loop is implemented such that the framerate is always stable
/// no matter if the methods called are handled faster than a frame
/// </remarks>
///
void GameLoop::Run()
{
	unsigned __int64 freq;
	unsigned __int64 startTime;
	unsigned __int64 endTime;
	double timerFrequency;
	double timeDifferenceInMilliseconds;
	double timeToSleep;
		
	SDL_Event loopEvent;

	while (!this->_done && SDL_PollEvent(&loopEvent) != -1) {
		this->_done |= this->_HandleEvents(loopEvent);

		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER *)&startTime);
		timerFrequency = (1.0/freq);

		QueryPerformanceCounter((LARGE_INTEGER *)&endTime);
		timeDifferenceInMilliseconds = ((endTime-startTime) * timerFrequency) * 1000;
		timeToSleep = MILLISECONDS_PER_FRAME - timeDifferenceInMilliseconds;
		if (timeToSleep > 0) {
			Sleep ((DWORD)timeToSleep);
		}
		this->_HandleFrame(loopEvent, timeToSleep);
	}
}

/// <summary>
/// Routine to handle all Gameobjects
/// </summary>
///
/// <remarks>
/// Gameobject methods are called in the following order:
/// - Input
/// - Update
/// - Render
/// </remarks>
///
/// <param name="sdlEvent">An event to be processed</param>
/// <param name="delay" type="double">The delay with which the update should be done</param>
///
void GameLoop::_HandleFrame(SDL_Event sdlEvent, double delay)
{
	for (auto gameobject : this->_manager->GameObjects()) {
		gameobject->Input(&sdlEvent);
	}

	for (auto gameobject : this->_manager->GameObjects()) {
		gameobject->Update(delay);
	}
	
	SDL_RenderClear(this->_renderer);
	for (auto gameobject : this->_manager->GameObjects()) {
		gameobject->Render(this->_renderer);
	}
	SDL_RenderPresent(this->_renderer);
}


///
/// <summary>
/// Process Keyboard events
/// </summary>
///
/// <param name="sdlEvent">Event to be processed</param>
///
bool GameLoop::_HandleKeystrokes(SDL_Event sdlEvent) 
{
	switch (sdlEvent.key.keysym.sym)
	{
		case SDLK_ESCAPE:
			return true;
			break;
		default:
			break;
	}
	return false;
}


///
/// <summary>
/// Process Mouse events
/// </summary>
///
/// <param name="sdlEvent">Event to be processed</param>
///
bool GameLoop::_HandleMouseMotion(SDL_Event sdlEvent)
{
	return false;
}

bool GameLoop::_HandleEvents(SDL_Event sdlEvent)
{
	switch(sdlEvent.type) {
		case SDL_MOUSEMOTION:
			return this->_HandleMouseMotion(sdlEvent);
			break;
		case SDL_KEYDOWN:
			return this->_HandleKeystrokes(sdlEvent);
			break;
		case SDL_QUIT: 
			return true;
			break;
		default:
			break;
	}

	return false;
}
