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
			Assert::IsNull(node.getParent());
		}

		/*
			Testing getting left side item. Add a node as a child. Position of item will not be affected.
			Adding 1 the new node should be on the left side.
		*/
		TEST_METHOD(getLeftTest)
		{
			TNode<int, int> node(2, 2);
			Assert::AreEqual(2, node.getItem());
			Assert::IsNull(node.getLeft());
			node.add(1, 1);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(1, node.getLeft()->getItem());
		}

		/*
			Testing getting right side item. Add a node as a child. Position of item will not be affected.
			Adding 4 the new node should be on the right side.
		*/
		TEST_METHOD(getRightTest)
		{
			TNode<int, int> node(2, 2);
			Assert::AreEqual(2, node.getItem());
			Assert::IsNull(node.getRight());
			node.add(4, 4);
			Assert::IsNotNull(node.getRight());
			Assert::AreEqual(4, node.getRight()->getItem());
		}

		/*
		    Testing Adding less than children. Add a node as a child. Position of item will not be affected.
			Adding 2 to the node, the new node should be on the right.
			Then adding two children 1 and 3. They should be shown as below
			    4
			   / \
			  2   x
			 / \   \
			1   3   x
		*/
		TEST_METHOD(TestLessThanChildren)
		{
			TNode<int, int> node(4, 4);
			node.add(2, 2);
			TNode<int, int>* left = node.getLeft();
			node.add(1, 1);
			node.add(3, 3);
			Assert::IsNotNull(left->getLeft());
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNotNull(left->getRight());
			Assert::AreEqual(3, left->getRight()->getItem());

		}

		/*
			Testing Adding greater than children. Add a node as a child. Position of item will not be affected.
			Adding 4 to the node, the new node should be on the right.
			Then adding two children 3 and 5. They should be shown as below
				2
			   / \
			  x   4
			 /   / \
			x	3   5
		*/
		TEST_METHOD(TestGreaterThanChildren)
		{
			TNode<int, int> node(2, 2);
			node.add(4, 4);
			TNode<int, int>* right = node.getRight();
			node.add(3, 3);
			node.add(5, 5);
			Assert::IsNotNull(right->getLeft());
			Assert::AreEqual(3, right->getLeft()->getItem());
			Assert::IsNotNull(right->getRight());
			Assert::AreEqual(5, right->getRight()->getItem());

		}

		/*
			Testing Count item method.
		*/
		TEST_METHOD(TestCount)
		{
			TNode<int, int> node(2, 2);
			node.add(4,4);
			node.add(6, 6);
			TNode<int, int>* left = node.getLeft();
			node.add(1, 1);
			node.add(3, 3);
			node.add(5, 5);
			node.add(7, 7);
			Assert::AreEqual(7, node.count());

		}
	};
}
