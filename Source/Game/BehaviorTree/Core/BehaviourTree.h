#pragma once
#include "Node.h"

namespace BehaviourTree
{
	
	class BehaviourTree
	{
	public:
		BehaciourTree() = default;
		~BehaviourTree() = default;

		NodeState tick()
		{
			if (_rootNode)
				return _rootNode->tick();
			return NodeState::FAILURE;
		}

	private:
		Node* _rootNode = nullptr;
	};
}