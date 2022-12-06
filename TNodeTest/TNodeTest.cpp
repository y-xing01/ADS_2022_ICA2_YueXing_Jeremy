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
		/*
			Test the data is set in the TNode constructor are all nullptr
		*/
		TEST_METHOD(constructorTest)
		{
			TNode<int, int> node(1, 1);
			Assert::AreEqual(1, node.getItem());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
			Assert::IsNull(node.getParentItem());
		}

		/*
			Testing getting left side item. Add a node as a child. All items should not be moved.
			By Adding 2 the new node should be on the left side.
		*/
		TEST_METHOD(getLeftTest)
		{
			TNode<int, int> node(4, 4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getLeft());
			node.add(2, 2);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(2, node.getLeft()->getItem());
		}

		/*
			Testing getting right side item. Add a node as a child. All items should not be moved.
			By Adding 2 the new node should be on the left side.
		*/
		TEST_METHOD(getRightTest)
		{
			TNode<int, int> node(4, 4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getRight());
			node.add(6, 6);
			Assert::IsNotNull(node.getRight());
			Assert::AreEqual(6, node.getRight()->getItem());
		}
	};
}
