#pragma once
#include "../../Core/Globals.h"
#include "../../Source/Game/BehaviorTree/Core/CompositeNode.h"
#include "Core/CompositeNode.h"
#include "Core/Node.h"

namespace BehaviourTree
{
	class Sequence : public CompositeNode
	{
		uint _currentIndex = 0;
	public:
		NodeState tick(const BlackBoard& bb) override
		{
			for (auto i = _currentIndex; i<_nodes.size(); ++i)
			{
				NodeState state = node[i]->tick(bb);
				// On enregistre l'index du noeud courant si il est en cours d'execution, 
				// pour reproendre a partir de ce noeud lors du prochain tick.
				if (state == NodeState::RUNNING)
					_currentIndex = i;

				if (state != NodeState::SUCCESS)
					return state;
			}

			return NodeState::SUCCESS;
		}
	};

	class Selector : public CompositeNode
	{
		NodeState tick(const BlackBoard& bb) override
		{

			for (auto i = _currentIndex; i < _nodes.size(); ++i)
			{
				NodeState state = node[i]->tick(bb);

				// On enregistre l'index du noeud courant si il est en cours d'execution, 
				// pour reproendre a partir de ce noeud lors du prochain tick.
				if (state == NodeState::RUNNING)
					_currentIndex = i;

				if (state != NodeState::FAILURE)
					return state;
			}

			return NodeState::FAILURE;
		}
	};
}
