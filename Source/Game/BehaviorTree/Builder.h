#pragma once

#include "ActionLeaves.h"
#include "Core/BehaviourTree.h"

namespace BehaviourTree
{
	class Builders
	{
	public:
		static BehaviourTree* TestSequence()
		{
			auto bt = new BehaviourTree();

			auto sn = new Sequence();
			sn->add(new DummySuccess());
			sn->add(new DummyFail());
			sn->add(new DummySuccess());

			bt->SetRootNode(sn);
		}

		static BehaviourTree* TestSelector()
		{
			auto bt = new BehaviourTree();

			auto sn = new Sequence();
			sn->add(new DummyFail());
			sn->add(new DummySuccess());
			sn->add(new DummyFail());

			bt->SetRootNode(sn);

			return bt;
		}

		static BehaviourTree* TestSequences()
		{
			auto bt = new BehaviourTree();

			auto sn = new Sequence();
			sn->add(new DummyWriteData());
			sn->add(new DummyReadData());
			sn->add(new DummySuccess());

			bt->SetRootNode(sn);

			return bt;
		}

		static BehaviourTree* TestBlackBoard()
		{
			auto bt = new BehaviourTree();

			auto sn = new Sequence();
			sn->add(new DummyWriteData());
			sn->add(new DummyReadData());
			sn->add(new DummySuccess());

			bt->SetRootNode(sn);
		
			return bt;
		}

		static BehaviourTree* TestRunningNode()
		{
			auto bt = new BehaviourTree();
			auto sn = new Selector();
			sn->add(new DummyFail());
			sn->add(new DummyRunning());
			bt->SetRootNode(sn);

			return bt;
		}
	
		static BehaviourTree* TestRepeater()
		{
			auto bt = new BehaviourTree();

			auto sn = new Sequence();
			auto repeater = new Game::Repeater(5);
			sn->add(new DummySuccess());
			sn->add(repeater);
			sn->add(new DummySuccess());
			sn->add(repeater);

			bt->SetRootNode(sn);

			return bt;
		}

		static BehaviourTree* TestDelay()
		{
			auto bt = new BehaviourTree();

			auto sn = new Sequence();
			auto delay = new Game::Delay(3);

			
			sn->add(delay);
			sn->add(new DummySuccess());
			sn->add(delay);
			sn->add(new DummySuccess());

			bt->SetRootNode(sn);

			return bt;
		}
	};


}
