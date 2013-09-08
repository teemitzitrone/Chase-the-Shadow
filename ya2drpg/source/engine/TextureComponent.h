#pragma once
#include "Component.h"
class TextureComponent :
	public Component
{
public:
	TextureComponent(void): _texture(nullptr), Component("Texture") {};
	TextureComponent(SDL_Texture* texture): _texture(texture), Component("Texture") {};
	virtual ~TextureComponent(void) {};
	void Input(SDL_Event*); 
	void Update(GameObject&);
	void Render(GameObject&, SDL_Renderer*);
	static TextureComponent* Factory(const std::string, SDL_Renderer*);
private:
	SDL_Texture* _texture;
};
