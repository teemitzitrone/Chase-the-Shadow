#include "GameLoop.h"
#include <vector>
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
		
		this->_HandleFrame(loopEvent);

		QueryPerformanceCounter((LARGE_INTEGER *)&endTime);
		timeDifferenceInMilliseconds = ((endTime-startTime) * timerFrequency) * 1000;
		timeToSleep = MILLISECONDS_PER_FRAME - timeDifferenceInMilliseconds;
		if (timeToSleep > 0) {
			Sleep ((DWORD)timeToSleep);
		}
	}
}

void GameLoop::_HandleFrame(SDL_Event sdlEvent)
{
	for (auto gameobject : this->_manager->GameObjects()) {
		gameobject->Input(&sdlEvent);
	}

	for (auto gameobject : this->_manager->GameObjects()) {
		gameobject->Update();
	}
	
	SDL_RenderClear(this->_renderer);
	for (auto gameobject : this->_manager->GameObjects()) {
		gameobject->Render(this->_renderer);
	}
	SDL_RenderPresent(this->_renderer);
}


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
