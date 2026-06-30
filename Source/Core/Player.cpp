#include "player.h"

#include <algorithm>
#include <cmath>
#include <raylib.h>

#include "GameConfig.h"

namespace Core
{
	Player::Player()
		: Player(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0)
	{
	}

	Player::Player(double x, double y)
		: Actor(x, y),
		_inputs{ false, false, false, false },
		_isJumping(false)
	{
		_w = PLAYER_WIDTH;
		_h = PLAYER_HEIGHT;

		_colorR = PLAYER_COLOR_R;
		_colorG = PLAYER_COLOR_G;
		_colorB = PLAYER_COLOR_B;
		_colorA = 1.0;

		_ay = PLAYER_GRAVITY;
	}

	Player::~Player()
	{
		
	}

	void Player::update()
	{
		float dt = GetFrameTime();

		_ax = 0.0;

		if (_inputs.left)
			_ax -= PLAYER_ACCEL;

		if (_inputs.right)
			_ax += PLAYER_ACCEL;

		if (!_isJumping && _inputs.jump)
		{
			_vy = PLAYER_JUMP_VELOCITY;
			_isJumping = true;
		}

		if (_inputs.down)
		{
			if (_h == PLAYER_HEIGHT)
				_y += PLAYER_HEIGHT - PLAYER_HEIGHT_CROUCH;

			_h = PLAYER_HEIGHT_CROUCH;
			_ay = PLAYER_GRAVITY_CROUCH;
		}
		else
		{
			if (_h == PLAYER_HEIGHT_CROUCH)
				_y -= PLAYER_HEIGHT - PLAYER_HEIGHT_CROUCH;

			_h = PLAYER_HEIGHT;
			_ay = PLAYER_GRAVITY;
		}

		Actor::update();

		if (!_inputs.left && !_inputs.right)
		{
			double sign = std::copysign(1.0, _vx);
			_vx -= dt * sign * PLAYER_DAMPING;

			if (std::copysign(1.0, _vx) != sign)
				_vx = 0.0;
		}

		_vx = std::clamp(_vx, -static_cast<double>(SPEED_LIMIT), static_cast<double>(SPEED_LIMIT));

		if (_x < 0.0)
		{
			_x = 0.0;
			_vx *= -PLAYER_WALL_BOUNCE;
		}
		else if (_x + _w > SCREEN_WIDTH)
		{
			_x = SCREEN_WIDTH - _w;
			_vx *= -PLAYER_WALL_BOUNCE;
		}

		if (_y + _h > SCREEN_HEIGHT)
		{
			_y = SCREEN_HEIGHT - _h;
			_vy = 0.0;
			_isJumping = false;
		}
	}

	void Player::setPosition(double x, double y)
	{
		_x = x;
		_y = y;
	}

	void Player::setDirection(bool left, bool right, bool down, bool jump)
	{
		_inputs.left = left;
		_inputs.right = right;
		_inputs.down = down;
		_inputs.jump = jump;
	}

	void Player::resetDirection()
	{
		_inputs.left = false;
		_inputs.right = false;
		_inputs.down = false;
		_inputs.jump = false;
	}

	void Player::render() const
	{
		Actor::render();

		Color eyeColor{ 0, 0, 0, 255 };
		int eyeOffset = 0;

		if (_vx > 0.0)
			eyeOffset = PLAYER_EYE_OFFSET;
		else if (_vx < 0.0)
			eyeOffset = -PLAYER_EYE_OFFSET;

		Rectangle eye{};
		eye.width = PLAYER_EYE_SIZE;
		eye.height = PLAYER_EYE_SIZE;

		eye.x = static_cast<float>(_x + _w / 4.0 - PLAYER_EYE_SIZE / 2.0 + eyeOffset);
		eye.y = static_cast<float>(_y + _h / 3.0 - PLAYER_EYE_SIZE / 2.0);
		DrawRectangleRec(eye, eyeColor);

		eye.x = static_cast<float>(_x + 3.0 * _w / 4.0 - PLAYER_EYE_SIZE / 2.0 + eyeOffset);
		DrawRectangleRec(eye, eyeColor);

		int mouthY = static_cast<int>(_y + 3.0 * _h / 4.0);
		DrawLine(
			static_cast<int>(_x + _w / 4.0),
			mouthY,
			static_cast<int>(_x + 3.0 * _w / 4.0),
			mouthY,
			eyeColor
		);
	}
}
