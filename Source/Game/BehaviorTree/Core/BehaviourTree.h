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
			_complete = true;

			if (_rootNode)
				return _rootNode->tick(_blackBoard);

			
			return NodeState::FAILURE;
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
