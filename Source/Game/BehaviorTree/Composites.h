#pragma once
#include "../../Source/Game/BehaviorTree/Core/CompositeNode.h"

namespace BehaviourTree
{
	class Sequence : public BehaviourTree::CompositeNode
	{
	public:
		NodeState tick() override
		{
			for (auto node : _nodes)
			{
				if (node->tick() == NodeState::FAILURE)
					return NodeState::FAILURE;
			}

			return NodeState::SUCCESS;
		}
	};

	class Selector : public BehaviourTree::CompositeNode
	{
		NodeState tick() override
		{
			for (auto node : _nodes)
			{
				if (node->tick() == NodeState::SUCCESS)
					return NodeState::SUCCESS;
			}

			return NodeState::FAILURE;
		}
	};
}