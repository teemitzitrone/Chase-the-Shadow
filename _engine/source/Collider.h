#ifndef _COLLIDER_H
#define _COLLIDER_H
#pragma once
#include "Vector2D.h"

namespace engine
{
	class Collider
	{
	public:
		Collider(void) {};
		virtual ~Collider(void) {};

	private:
		Vector2D position;
	};
}
#endif
