#pragma once
#include "TextureComponent.h"
class AnimationComponent :
	public TextureComponent
{
public:
	AnimationComponent(int frames = 8): _frames(frames) {};
	AnimationComponent(SDL_Texture* texture, int frames = 8): TextureComponent(texture), _frames(frames) {};
	virtual ~AnimationComponent(void) {};
	void Update(GameObject&);

	static AnimationComponent* Factory(const std::string, SDL_Renderer*, int frames = 8);
private:
	int _frames;
};
