#pragma once
#include "CompositeNode.h"

namespace BehaviourTree
{
	class Selector : public CompositeNode
	{
	public:
		NodeState tick( BlackBoard& bb);
	};
}