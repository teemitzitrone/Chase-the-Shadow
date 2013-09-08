#pragma once
#include "TextureComponent.h"
class AnimationComponent :
	public TextureComponent
{
public:
	AnimationComponent(void): _frames(8) {};
	AnimationComponent(SDL_Texture* texture): TextureComponent(texture), _frames(8) {};
	virtual ~AnimationComponent(void) {};
	void Update(GameObject&);

	static AnimationComponent* Factory(const std::string, SDL_Renderer*);
private:
	int _frames;
};
