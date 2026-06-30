#pragma once
#include "Core/LeafNode.h"
#include "Core/BlackBoard.h"
#include "../../Core/Globals.h"

namespace BehaviourTree
{
	class DummySuccess : public LeafNode
	{
	public:
		NodeState tick( BlackBoard& bb) override
		{
			Core::log("DummySuccess Leaf");
				return NodeState::SUCCESS;
		}
	};

	class DummyFail : public LeafNode
	{
	public:
		NodeState tick( BlackBoard& bb) override
		{
			Core::log("DummyFail Leaf");
			return NodeState::FAILURE;
		}
	};

	class DummyRunning : public LeafNode
	{
	public:
		NodeState tick( BlackBoard& bb) override
		{
			Core::log("DummyRunning Leaf");
			return NodeState::RUNNING;
		}
	};

	class DummyWriteData : public LeafNode
	{
	public:
		NodeState tick( BlackBoard& bb) override
		{
			Core::log("DummyWriteData Leaf");
			bb.set<bool>("TestData", true);
			Core::log(" Add TestData to BB");
			return NodeState::SUCCESS;
		}
	};

	class DummyReadData : public LeafNode
	{
	public:
		NodeState tick( BlackBoard& bb) override
		{
			auto data = bb.get<bool>("TestData", false);
			if (data)
				Core::log(" Get TestData from BB SUCCESS");
			else
				Core::log("FAILED to get TestData from BB");
			Core::log(" Get TestData from BB");
			return NodeState::SUCCESS;
		}
	};
}
