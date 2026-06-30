#pragma once
#include "Actor.h"

namespace Core
{
	class Player : public Actor
	{
	public:
		Player();
		Player(double x, double y);
		~Player() override;

		void update() override;
		void render() const override;

		void setPosition(double x, double y);
		void setDirection(bool left, bool right, bool down, bool jump);
		void resetDirection();

	private:
		struct Inputs
		{
			bool left;
			bool right;
			bool down;
			bool jump;
		};

		Inputs _inputs;
		bool _isJumping;
	};
}
