#pragma once

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
			sn->add(new DummySuccess());
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

			auto sn (new DummyRunning());

			bt->SetRootNode(sn);

			return bt;
		}
	};


}
