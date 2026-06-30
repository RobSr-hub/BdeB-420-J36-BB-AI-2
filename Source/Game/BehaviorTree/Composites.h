#pragma once
#include "../../Core/Globals.h"
#include "../../Source/Game/BehaviorTree/Core/CompositeNode.h"
#include "Core/CompositeNode.h"
#include "Core/Node.h"

namespace BehaviourTree
{
	class Sequence : public CompositeNode
	{
	public:
		NodeState tick(const BlackBoard& bb) override
		{
			Core::log("Sequence");
			for (auto node : _nodes)
			{
				NodeState state = node->tick(bb);
				if (state != NodeState::SUCCESS)
					return state;
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
				NodeState state = node->tick(bb);
				if (state != NodeState::FAILURE)
					return state;
			}

			return NodeState::FAILURE;
		}
	};
}
