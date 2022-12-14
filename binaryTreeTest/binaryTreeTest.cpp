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

		/*
			Test the remove function to try and remove a leaf node
			to test this we will use the following tree
			    4
			   / \
              2   6
		     / \ / \
		    1  3 5  7
		*/
		TEST_METHOD(TestRemoveLeafNode)
		{
			//Creating Tree
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);

			//Removing Leaf
			Assert::AreEqual(7, tree.count());
			tree.remove(5);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::IsNull(right->getLeft());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		/*
		Test the remove function to try and remove a node with one child to the right
		to test this we will use the following tree
				4
			   / \
			  2   6
			 / \ / \
			   3 5  7
			         \
					  8
		*/
		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			//Creating Tree
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(8, 8);
			Assert::AreEqual(7, tree.count());
			tree.remove(7);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(8, right->getRight()->getItem());
		}

		/*
			Test the remove function to try and remove a leaf node
			to test this we will use the following tree
				4
			   / \
			  2   6
			 / \ / \
			1  3 5  7
		*/

		TEST_METHOD(TestRemoveNodeWithTwoChildren)
		{
			//Creating Tree
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);

			//Counting Tree
			Assert::AreEqual(7, tree.count());

			//Removing key
			tree.remove(2);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNull(left->getRight());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		/*
			Test the remove function to try and a node with multiple children
			to test this we will use the following tree:
					  8
                    /   \
                   /     \
                  /       \
                 /         \
                4          12
               / \        /   \
              2   6      10   14
             / \ / \    / \   / \
			1  3 5  7  9  11 13 15

			When we remove a node in the middle of the tree, the algorithm
			should move the next lowest item up to the place of the removed node.
			In this case 13 will be moved up to the place of 12
		*/

		TEST_METHOD(TestRemoveNodeWithMultipleChildren)
		{
			//Creating Tree
			BinaryTree<int, int> tree;
			tree.add(8, 8);
			tree.add(4, 4);
			tree.add(12, 12);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(10, 10);
			tree.add(14, 14);
			tree.add(9, 9);
			tree.add(11, 11);
			tree.add(13, 13);
			tree.add(15, 15);
			//Counting Tree
			Assert::AreEqual(15, tree.count());

			//Checking and removing root
			Assert::IsNotNull(tree.root->getRight()->getRight()->getLeft());
			Assert::AreEqual(13, tree.root->getRight()->getRight()->getLeft()->getItem());
			tree.remove(12);
			Assert::AreEqual(14, tree.count());
			Assert::AreEqual(13, tree.root->getRight()->getItem());
			Assert::IsNull(tree.root->getRight()->getRight()->getLeft());
		}		

		/*
			Test the search function to try and search an item
			to test this we will use the following tree
				4
			   / \
			  2   6
			 / \ / \
			1  3 5  7
		*/
		TEST_METHOD(TestSearchItem)
		{
			//Creating Tree
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(15, 15);
			
			//Searching if key is in tree
			bool result = tree.search(7);
			Assert::AreEqual(true, result);
		}

		/*
			Test the find Depth function to find the depth of tree
			to test this we will use the following tree
				3
			   / \
			  2   x
			 /     \
			1       x
		*/
		TEST_METHOD(TestFindDepth)
		{
			//Creating Tree
			BinaryTree<int, int> tree;
			tree.add(3, 3);
			tree.add(2, 2);
			tree.add(1, 1);

			//Getting Depth
			int depth = tree.getDepth(tree.root, 1);
			Assert::AreEqual(2, depth);
		}

		/*
			Test the find Height function to find the depth of tree
			to test this we will use the following tree
				1
			   / \
			  x   2
			 /     \
			x       3
					 \
					  4
					   \
					    5
						 \
						  6
		*/
		TEST_METHOD(TestGetHeight)
		{
			//Creating Tree
			BinaryTree<int, int> tree;
			tree.add(1, 1);
			tree.add(2, 2);
			tree.add(3, 3);
			tree.add(4, 4);
			tree.add(5, 5);
			tree.add(6, 6);

			//Getting Height
			int height = tree.getHeight(tree.root);

			Assert::AreEqual(6, height);
		}

		/*
			Test the subtree function to find the node
			to test this we will use the following tree
			   4
			  / \
			 2   6
		    / \ / \
		   1  3 5  7
		*/
		TEST_METHOD(TestSubtree)
		{
			BinaryTree<int, int> tree;

			// Insert some nodes into the tree
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);

			// Search for the node with key 5
			TNode<int, int>* node = tree.subtree(tree.root, 5);

			// Check that the returned node is not NULL
			Assert::IsNotNull(node);

			// Check that the returned node has the expected key and value
			Assert::AreEqual(node->getKey(), 5);
			Assert::AreEqual(node->getItem(), 5);
		}

		/*
			Test the isBalance function to find if tree is balanced
			to test this we will use the following tree
				4
			   / \
			  2   6
			 / \ / \
			1  3 5  7
		*/
		TEST_METHOD(TestIsBalanced)
		{
			// Create a binary tree and add some keys to it
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);

			// Check if the tree is balanced
			bool is_balanced = tree.isBalanced();

			// Verify that the tree is balanced
			Assert::IsTrue(is_balanced);
		}

		/*
			Test the isBalance function to find if tree is balanced
			to test this we will use the following tree
				4
			   / \
			  2  
			 / \
			1  3 
		*/		
		TEST_METHOD(TestBalanceTree)
		{
			// Create a binary tree and add some keys to it
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(1, 1);
			tree.add(3, 3);


			// Balance the tree
			balanceTree(tree);

			// Verify that the tree is balanced
			Assert::IsTrue(tree.isBalanced());
		}	

		//TEST_METHOD(TestDeleteNodeChildren)
		//{
			//BinaryTree<int, int> tree;

			// Insert some nodes into the tree
			//tree.add(7, 10);
			//tree.add(3, 20);
			//tree.add(11, 30);
			//tree.add(1, 40);
			//tree.add(5, 50);
			//tree.add(9, 60);
			//tree.add(13, 70);

			// Remove a leaf node with key = 1
			//tree.deleteNodeChildren(tree.root, 1);

			// Check that the node with key = 1 is no longer in the tree
			//Assert::IsFalse(tree.search(1));

			// Remove a node with one child, key = 5
			//tree.deleteNodeChildren(tree.root, 5);

			// Check that the node with key = 5 is no longer in the tree
			//Assert::IsFalse(tree.search(5));

			// Check that the left child of the node with key = 3 is now the node with key = 1
			//int res = tree.root->getLeft()->getLeft()->getKey();
			//Assert::AreEqual(1, res);
		//}
	};
}
