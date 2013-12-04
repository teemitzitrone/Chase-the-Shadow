#ifndef _TRANSFORMCOMPONENT_H
#define _TRANSFORMCOMPONENT_H
#include <SDL.h>
#include "Component.h"
namespace engine
{
	enum UnitSpeed {
		None,
		Slow,
		Normal,
		Fast,
	};


	class TransformComponent :
	public Component
	{
	public:
		TransformComponent(void): Component("Transform") {};
		TransformComponent(SDL_Rect position, SDL_Rect rotation, SDL_Rect* scale, UnitSpeed speed): _speed(speed), _position(position), _rotation(rotation), _scale(scale), Component("Transform") {};
		virtual ~TransformComponent(void)
		{
			/// delete this->_scale;
		};
		void Input(GameObject&, SDL_Event*); 
		void Update(GameObject&, double);
		void Render(GameObject&, SDL_Renderer*);
		SDL_Rect GetPosition();
		SDL_Rect GetRotation();
		SDL_Rect* GetScale();
		static TransformComponent* Factory(UnitSpeed = UnitSpeed::Normal);
		static TransformComponent* Factory(SDL_Rect, UnitSpeed = UnitSpeed::Normal);
		static TransformComponent* Factory(SDL_Rect, SDL_Rect, UnitSpeed = UnitSpeed::Normal);
		static TransformComponent* Factory(SDL_Rect, SDL_Rect, SDL_Rect*, UnitSpeed = UnitSpeed::Normal);
	private:
		UnitSpeed _speed;
		SDL_Rect _position;
		SDL_Rect _rotation;
		SDL_Rect* _scale;
	};
}
#endif