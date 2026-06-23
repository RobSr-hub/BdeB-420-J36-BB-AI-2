#pragma once
#include "Node.h"


namespace BehaviourTree
{
	class CompositeNode : Node
	{
	public:
		virtual ~CompositeNode()
		{
			for (Node* node : _nodes)
			{
				delete node;
			}
		};

	protected:
		std::vector<Node*> _nodes;
		CompositeNode() override = default;
	};
}