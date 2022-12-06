#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_TREE/BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace binaryTreeTest
{
	TEST_CLASS(binaryTreeTest)
	{
	public:
		/*
			This test ensures a node is created at the root when
			an element is added to an empty binary tree
		*/
		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<int, int> tree;
			tree.add(1, 1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(1, tree.root->getKey());
		}

		/*
			This test ensures a node is created on the left branch
			when value is less than root.
		*/
		TEST_METHOD(TestAddToRootLeft)
		{
			BinaryTree<int, int> tree;
			tree.add(2,2);
			tree.add(1,1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			Assert::IsNotNull(left);
			Assert::AreEqual(1, left->getItem());
		}

		/*
			This test ensures a node is created on the right branch
			when value is less than root.
		*/
		TEST_METHOD(TestAddToRootRight)
		{
			BinaryTree<int, int> tree;
			tree.add(2, 2);
			tree.add(3, 3);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			TNode<int, int>* right = tree.root->getRight();
			Assert::IsNotNull(right);
			Assert::AreEqual(3, right->getItem());
		}

		/*
			Test the count function for empty tree
		*/

		TEST_METHOD(TestCountOnEmpty)
		{
			BinaryTree<int, int> tree;
			Assert::AreEqual(0, tree.count());
		}

		/*
		Test the count function for full tree
		to test this we will use the following tree
	          4
		     / \
		    2   6
		   / \ / \
          1  3 5  7
		*/
		TEST_METHOD(TestCountOnFullTree)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);

			Assert::AreEqual(7, tree.count());
		}

		/*
		Test the remove function to try and remove an item not found
		to test this we will use the following tree
			  4
			 / \
			2   6
		   / \ / \
		  1  3 5  7
		*/
		TEST_METHOD(TestRemoveItemNotPresent)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			Assert::AreEqual(7, tree.count());
			tree.remove(8);
			Assert::AreEqual(7, tree.count());
			Assert::AreEqual(4, tree.root->getKey());
			Assert::AreEqual(2, tree.root->getLeft()->getKey());
			Assert::AreEqual(6, tree.root->getRight()->getKey());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getKey());
			Assert::AreEqual(3, left->getRight()->getKey());
			Assert::AreEqual(5, right->getLeft()->getKey());
			Assert::AreEqual(7, right->getRight()->getKey());
		}
	};
}
