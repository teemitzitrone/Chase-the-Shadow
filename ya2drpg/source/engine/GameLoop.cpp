#include "GameLoop.h"
#include <vector>
#include <Windows.h>
#include <time.h>

#define FRAMES_PER_SECOND 60.0
#define MILLISECONDS_PER_FRAME 1000.0 / FRAMES_PER_SECOND

GameLoop::GameLoop(void)
{
	this->_done = false;
}

GameLoop::~GameLoop(void)
{
}

void GameLoop::RegisterController(GameObject* controller)
{
	std::vector<GameObject*>::iterator it = this->_controllers.begin();

	this->_controllers.push_back(controller);
	
}

#define screenwidth 800
#define screenheight 600

void GameLoop::Run()
{
	unsigned __int64 freq;
	unsigned __int64 startTime;
	unsigned __int64 endTime;
	double timerFrequency;
	double timeDifferenceInMilliseconds;
	double timeToSleep;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		exit(1);
	}

	
	this->_screen = SDL_SetVideoMode(screenwidth, screenheight, 32, SDL_HWSURFACE);
	if (this->_screen == nullptr) {
		SDL_Quit();
		//error("SDL_SetVideoMode failed with message: " + (string) SDL_GetError());
	}
	
	SDL_Event loopEvent;

	while (!this->_done && SDL_PollEvent(&loopEvent) != -1) {
		this->_done |= this->_HandleEvents(loopEvent);

		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER *)&startTime);
		timerFrequency = (1.0/freq);

		for (auto controller : this->_controllers) {
			controller->Update();
		}
		
		QueryPerformanceCounter((LARGE_INTEGER *)&endTime);
		timeDifferenceInMilliseconds = ((endTime-startTime) * timerFrequency) * 1000;
		timeToSleep = MILLISECONDS_PER_FRAME - timeDifferenceInMilliseconds;
		if (timeToSleep > 0) {
			Sleep ((DWORD)timeToSleep);
		}
		
		SDL_Flip(this->_screen);
	}
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