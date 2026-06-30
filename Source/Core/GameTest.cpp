#include "GameTest.h"

#include <raylib.h>
#include "../Game/BehaviorTree/Builder.h"

namespace Core
{
	GameTest::GameTest()
	{
		InitWindow(720, 480, "GameTest");
		SetTargetFPS(30);

		//_tree = BehaviourTree::Builders::TestSequence();
	}

	GameTest::~GameTest()
	{
		CloseWindow();
	}

	void GameTest::handleInput()
	{
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
		_tree.tick();
			
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

