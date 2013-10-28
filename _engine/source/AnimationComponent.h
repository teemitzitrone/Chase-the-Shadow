#ifndef _ANIMATIONCOMPONENT_H
#define _ANIMATIONCOMPONENT_H
#pragma once
#include "TextureComponent.h"

namespace engine
{
	class AnimationComponent :
		public TextureComponent
	{
	public:
		AnimationComponent(int frames = 8, double speed = 4.0, double anim = 600.0): _frames(frames), _animation(anim), _speed(speed), _timeToAnimation(anim/speed) {};
		AnimationComponent(SDL_Texture* texture, int frames = 8, double speed = 4.0, double anim = 600.0): TextureComponent(texture), _frames(frames), _animation(anim), _speed(speed), _timeToAnimation(anim/speed) {};
		virtual ~AnimationComponent(void) {};
		void Update(GameObject&, double);

		static AnimationComponent* Factory(const std::string, SDL_Renderer*, int frames = 8);
	private:
		int _frames;
		const double _animation;
		double _speed;
		double _timeToAnimation;
	};
}
#endif