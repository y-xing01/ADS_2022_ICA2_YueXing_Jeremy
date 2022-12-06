#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/TNode.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/Utilities.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TNodeTest
{
	TEST_CLASS(TNodeTest)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			TNode<int, int> node(1, 1);
			Assert::AreEqual(1, node.getItem());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
			Assert::IsNull(node.getParentItem());
		}
	};
}
