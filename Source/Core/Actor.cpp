#include "Actor.h"

#include <raylib.h>

#include "Globals.h"

namespace Core
{
	Actor::Actor()
		: _x(0.0), _y(0.0),
		_w(0.0), _h(0.0),
		_vx(0.0), _vy(0.0),
		_ax(0.0), _ay(0.0),
		_colorR(0.0), _colorG(0.0), _colorB(0.0), _colorA(0.0)
	{
	}

	Actor::Actor(double x, double y)
		: _x(x), _y(y),
		_w(0.0), _h(0.0),
		_vx(0.0), _vy(0.0),
		_ax(0.0), _ay(0.0),
		_colorR(0.0), _colorG(0.0), _colorB(0.0), _colorA(0.0)
	{
	}

	void Actor::init(double x, double y)
	{
		_x = x;
		_y = y;
		_deleteMe = false;

	}

	void Actor::move()
	{
		float dt = GetFrameTime();

		_vx += dt * _ax;
		_vy += dt * _ay;

		_x += dt * _vx;
		_y += dt * _vy;
	}

	void Actor::update()
	{
		move();
	}

	void Actor::render() const
	{
		Color color
		{
			static_cast<uchar>(_colorR * 255),
			static_cast<uchar>(_colorG * 255),
			static_cast<uchar>(_colorB * 255),
			static_cast<uchar>(_colorA * 255)
		};

		Rectangle rect{};
		rect.x = static_cast<float>(_x);
		rect.y = static_cast<float>(_y);
		rect.width = static_cast<float>(_w);
		rect.height = static_cast<float>(_h);

		DrawRectangleRec(rect, color);
	}
}
