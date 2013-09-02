#pragma once
#include "Component.h"
#include <string>
class TextureComponent :
	public Component
{
public:
	TextureComponent(void): _texture(nullptr) {};
	TextureComponent(SDL_Texture* texture): _texture(texture) {};
	virtual ~TextureComponent(void) {};
	void Input(SDL_Event*); 
	void Update(GameObject&);
	void Render(GameObject&, SDL_Renderer*);
	static TextureComponent* Factory(const std::string, SDL_Renderer*);
private:
	SDL_Texture* _texture;
};
