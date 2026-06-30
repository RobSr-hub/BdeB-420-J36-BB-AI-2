#pragma once
#include "../../Core/Globals.h"
#include "../../Source/Game/BehaviorTree/Core/CompositeNode.h"
#include "Core/Node.h"

namespace BehaviourTree
{
	class Sequence : public BehaviourTree::CompositeNode
	{
	public:
		NodeState tick(const BlackBoard& bb) override
		{
			Core::log("Sequence");
			for (auto node : _nodes)
			{
				if (node->tick(bb) == NodeState::FAILURE)
					return NodeState::FAILURE;
			}

			return NodeState::SUCCESS;
		}
	};

	class Selector : public BehaviourTree::CompositeNode
	{
		NodeState tick(const BlackBoard& bb) override
		{
			Core::log("Selector");

			for (auto node : _nodes)
			{
				if (node->tick() == NodeState::SUCCESS)
					return NodeState::SUCCESS;
			}

			return NodeState::FAILURE;
		}
	};
}
