#pragma once
#include "GameBase.h"
#include "Player.h"
#include "../Game/BehaviorTree/Core/BehaviourTree.h"

namespace BehaviourTree
{
	class BehaviourTree;
}

namespace Core
{
	class GameTest : public GameBase
	{
		BehaviourTree::BehaviourTree* _tree;

	public:
		GameTest();
		~GameTest() override;

		void handleInput() override;
		void update() override;
		void render() override;

	private:
		Player _player;
	};
}
