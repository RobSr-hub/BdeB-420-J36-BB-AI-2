#include "GameTest.h"

#include <raylib.h>
#include "../Game/BehaviorTree/Builder.h"
#include "GameConfig.h"

namespace Core
{
	GameTest::GameTest()
		: _player(SCREEN_WIDTH / 2.0, SCREEN_HEIGHT / 2.0)
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
		SetTargetFPS(FPS);

		_tree = BehaviourTree::Builders::TestRunningNode();
		_loop = true;
	}

	GameTest::~GameTest()
	{
		delete _tree;
		_tree = nullptr;
		CloseWindow();
	}

	void GameTest::handleInput()
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
			_player.setPosition(GetMouseX(), GetMouseY());

		bool directionPressed =
			IsKeyDown(KEY_LEFT) ||
			IsKeyDown(KEY_RIGHT) ||
			IsKeyDown(KEY_DOWN) ||
			IsKeyDown(KEY_UP) ||
			IsKeyDown(KEY_SPACE);

		if (directionPressed)
		{
			_player.setDirection(
				IsKeyDown(KEY_LEFT),
				IsKeyDown(KEY_RIGHT),
				IsKeyDown(KEY_DOWN),
				IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE)
			);
		}
		else
		{
			_player.resetDirection();
		}

		int key = GetKeyPressed();
		switch (key)
		{
		case KEY_ESCAPE:
			_loop = false;
			break;
		}
	}

	void GameTest::update()
	{
		if (!_tree->isComplete())
			_tree->tick();

		_player.update();
			
	}

	void GameTest::render()
	{
		BeginDrawing();
		{
			ClearBackground(BLANK);
			DrawFPS(20, 20);
			_player.render();
		}
		EndDrawing();
	}
}

