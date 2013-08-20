#include <iostream>

#include <SDL.h>

int main(int argc, char *argv[])
{
	int get;
	SDL_Rect rect = {1, 1, 1, 1};

	std::cout << "SDL_Rect w=" << rect.w << std::endl;
	std::cin >> get;

	return 0;
}