#include "player.h"

namespace Core
{
	Player::Player()
	{
		_position = { 100.0f, 100.0f };
		_speed = 5.0f;
	}

	Player::~Player()
	{
		
	}

	void Player::update()
	{
		if (IsKeyDown(KEY_D))
			_position.x += _speed;

		if (IsKeyDown(KEY_A))
			_position.x -= _speed;

		if (IsKeyDown(KEY_S))
			_position.y += _speed;

		if (IsKeyDown(KEY_W))
			_position.y -= _speed;
	}

	void Player::render()
	{
		DrawRectangle(
			static_cast<int>(_position.x),
			static_cast<int>(_position.y),
			50,
			50,
			BLUE
		);
	}
}
