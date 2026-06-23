#pragma once
#include <cmath>
#include <raylib/>
#include "Node.h"

namespace BehaviourTree
{
	class BehaviourTree
	{
	private:
		Node* _rootNode = nullptr;

	public:
		BehaciourTree() = default;
		~BehaviourTree() = default;

		NodeState tick() const
		{
			//TraceLog(log())
			if (_rootNode)
				return _rootNode->tick();
			return NodeState::FAILURE;
		}

	
	};
}