#pragma once

#include "CompositeNode.h"

namespace BehaviourTree
{
	class Sequence : public CompositeNode
	{
	public:
		NodeState tick() override;
	};
}