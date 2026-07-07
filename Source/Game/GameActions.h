#pragma once
#include <raylib.h>

#include "BehaviorTree/Core/LeafNode.h"
#include "BehaviorTree/Core/Node.h"
#include "../Source/Core/Actor.h"

using namespace BehaviourTree;
using namespace Core;

namespace Game
{
	class MoveActor : public LeafNode
	{
		float _duration;
		float _elapsed = 0.0f;

	public:
		MoveActor(uint duration)
			: _duration(duration)
		{
			auto data = bb.get<bool>("TestData", false);
		}

		NodeState tick(BlackBoard& bb) override
		{
			_elapsed += GetFrameTime();
			if (_elapsed < _duration)
			{
				// TODO Call Move on the player
				auto actor = bb.get<Core::Actor>("Player", nullptr);
				return NodeState::RUNNING;
			}

			_elapsed = 0.0f;
			return NodeState::SUCCESS;
		}
	};
}
