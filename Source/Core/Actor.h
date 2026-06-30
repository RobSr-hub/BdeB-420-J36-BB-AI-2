#pragma once

namespace Core
{
	class Actor
	{
	public:
		Actor();
		Actor(double x, double y);
		virtual ~Actor() = default;

		virtual void init(double x, double y);
		virtual void update();
		virtual void render() const;

	protected:
		double _x;
		double _y;
		double _w;
		double _h;
		double _vx;
		double _vy;
		double _ax;
		double _ay;
		double _colorR;
		double _colorG;
		double _colorB;
		double _colorA;
	};
}
