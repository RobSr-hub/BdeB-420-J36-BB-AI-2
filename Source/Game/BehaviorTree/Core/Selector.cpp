#include "Selector.h"

namespace BehaviourTree
{
	NodeState Selector::tick( BlackBoard& bb)
	{
		for (Node* child : _nodes)
		{
			NodeState result = child->tick(bb);

			if (result == NodeState::FAILURE)
				return NodeState::FAILURE;

			if (result == NodeState::RUNNING)
				return NodeState::RUNNING;
		}

		return NodeState::SUCCESS;
	}
}