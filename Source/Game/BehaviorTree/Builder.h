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
			sn->add(new DummyFail());
			sn->add(new DummySuccess());

			bt->SetRootNode(sn);
		}

		static BehaviourTree* TestSelector()
		{
			auto bt = new BehaviourTree();

			auto sn = new Sequence();
			sn->add(new DummySuccess());
			sn->add(new DummyFail());
			sn->add(new DummyFail());

			bt->SetRootNode(sn);
		}

		static BehaviourTree TestComposites()
		{
			auto bt = new BehaviourTree();
			auto sln = new Selector();
			auto sqn = new Sequence();

			sqn->add(new DummySuccess());
			sqn->add(sln);
			sqn->add(new DummySuccess());

			bt->SetRootNode(sqn);
		}
	};


}
