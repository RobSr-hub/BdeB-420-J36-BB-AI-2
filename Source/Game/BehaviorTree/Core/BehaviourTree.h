#pragma once
#include <cmath>
#include "Sequence.h"
#include "Selector.h"
#include "../DummyLeaves.h"
#include "BlackBoard.h"

namespace BehaviourTree
{
	class BehaviourTree
	{
	private:
		Node* _rootNode = nullptr;
		bool _complete = false;

		BlackBoard _blackBoard;
		NodeState treeState;

	public:
		BehaviourTree()
		{
			//TestSequence();
			//TestSelector();
			TestComposites();
		};

		~BehaviourTree()
		{
			delete _rootNode;
			_rootNode = nullptr;
		}

		void SetRootNode(Node* node)
		{
			_rootNode = node;
		}

		NodeState tick()
		{
			if (!_rootNode)
				return NodeState::FAILURE;

			NodeState state = _rootNode->tick(_blackBoard);
			_complete = state == NodeState::SUCCESS || state == NodeState::FAILURE;

			treeState = _rootNode->tick(_blackBoard);
		return treeState;
		}

		bool isComplete()
		{
			return _complete;
		}

	private:
		// Testing case for the tree, can be replaced with more complex tree structure
		void TestSequence()
		{
			auto sn = new Sequence();
			sn->add(new DummySuccess());
			sn->add(new DummyFail());
			sn->add(new DummySuccess());

			_rootNode = sn;
		}

		void TestSelector()
		{
			auto sn = new Selector();
			sn->add(new DummySuccess());
			sn->add(new DummyFail());
			sn->add(new DummyFail());

			_rootNode = sn;
		}

		void TestComposites()
		{
			auto sln = new Selector();
			auto sqn = new Sequence();
		
			sqn->add(new DummySuccess);
			sqn->add(sln);
			sqn->add(new DummySuccess());

			sln->add(new DummyFail());
			sln->add(new DummyFail());
			sln->add(new DummyFail());
		}
	
	};
}
