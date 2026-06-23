#pragma once
#include <raylib.h>

namespace Core
{
	class Actor
	{
	public:
		Actor();
		virtual ~Actor();

		virtual void update();
		virtual void render();

	protected:
		Vector2 _position;
		float _speed;
	};
}
