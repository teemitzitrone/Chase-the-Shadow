#ifndef _COLLIDER_H__
#define _COLLIDER_H__
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
