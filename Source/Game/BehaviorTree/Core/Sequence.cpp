#include "Sequence.h"

namespace BehaviourTree
{
	NodeState Sequence::tick()
	{
		for (Node* child : _nodes)
		{
			NodeState result = child->tick();

			if (result == NodeState::FAILURE)
				return NodeState::FAILURE;

			if (result == NodeState::RUNNING)
				return NodeState::RUNNING;

		}

		return NodeState::SUCCESS;
	}
}