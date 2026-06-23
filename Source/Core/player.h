#pragma once
#include "Actor.h"

namespace Core
{
	class Player : public Actor
	{
	public:
		Player();
		~Player() override;

		void update() override;
		void render() override;
	};
}