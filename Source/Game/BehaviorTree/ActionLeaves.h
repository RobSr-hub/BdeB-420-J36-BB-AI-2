#pragma once
#include "Core/BehaviourTree.h"
#include <raylib.h>

using namespace Core;
using namespace BehaviourTree;

namespace Game
{
	class Repeater : public LeafNode
	{
		uint _maxLoop;
		uint _loop = 0;
	
	public:
		Repeater(uint maxloop)
			: _maxLoop(maxloop)
		{}

		NodeState tick(BlackBoard& bb) override
		{
			if (++_loop < _maxLoop)
				return NodeState::RUNNING;

			_loop = 0;
			return NodeState::SUCCESS;
		}
	};

	class Delay : public LeafNode
	{
		float _duration;
		float _elapsed = 0.0f;

	public:
		Delay(float duration)
			 : _duration(duration) {}

		NodeState tick(BlackBoard& bb) override
		{
			_elapsed += GetFrameTime();
			if (_elapsed < _duration)
				return NodeState::RUNNING;

			_elapsed = 0.0f;
			return NodeState::SUCCESS;
		}
	};
}
