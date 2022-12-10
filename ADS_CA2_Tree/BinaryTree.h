#pragma once
#include "TNode.h"
#include <vector>
#include <iostream>
#include <exception>

using namespace std;
template <typename K, typename E>
class BinaryTree
{
	void addItemToArray(TNode<K, E>* node, int& pos, int* arr);
public:
	TNode<K, E>* root;
	TNode<K, E>* subtree(TNode<K, E>* node, K key);
	BinaryTree();
	bool remove(K key);
	bool search(K key);
	int count();
	int findDepth(TNode<K, E>* node, K key);
	int findHeight(TNode<K, E>* node, K key, int& height);
	int getHeight(TNode<K, E>* node, K key);

	void add(K key, E item);
	void printInOrder();
	void printInOrder(TNode<K, E>* node);
	void printPreOrder();
	void printPreOrder(TNode<K, E>* node);
	void printPostOrder();
	void printPostOrder(TNode<K, E>* node);
	void clear();

	K* toArray();
	~BinaryTree();
};

//Constructor
template <typename K, typename E>
BinaryTree<K, E>::BinaryTree()
{
	root = nullptr;
}

//Destructor
template <typename K, typename E>
BinaryTree<K, E>::~BinaryTree()
{
	delete root;
}

//Adding Binary Tree
template <typename K, typename E>
void BinaryTree<K, E>::add(K key, E item)
{
	if (root == nullptr)
	{
		root = new TNode<K, E>();		
		root->setKey(key);
		root->setItem(item);
	}
	else
	{
		root->add(key, item);
	}
}

//Counting root
template <typename K, typename E>
int BinaryTree<K, E>::count()
{
	if (root == nullptr)
		return 0;
	return root->count();
}

//Removing node
template <typename K, typename E>
bool BinaryTree<K, E>::remove(K key)
{
	TNode<K, E>* toBeRemoved = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{

		if (toBeRemoved->getKey() == key)
		{
			found = true;
		}
		else
		{
			parent = toBeRemoved;
			if (toBeRemoved->getKey() > key)
			{
				toBeRemoved = toBeRemoved->getLeft();
			}
			else
			{
				toBeRemoved = toBeRemoved->getRight();
			}
		}
	}
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		TNode<K, E>* newChild;
		if (toBeRemoved->getLeft() == nullptr)
		{
			newChild = toBeRemoved->getRight();
		}
		else
		{
			newChild = toBeRemoved->getLeft();
		}
		if (parent == nullptr)
		{
			root = newChild;
		}
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(newChild);
		}
		else
		{
			parent->setRight(newChild);
		}
		return true;
	}

	TNode<K, E>* smallestParent = toBeRemoved;
	TNode<K, E>* smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr)
	{
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}
	toBeRemoved->setItem(smallest->getItem());
	if (smallestParent == toBeRemoved)
	{
		smallestParent->setRight(smallest->getRight());
	}
	else
	{
		smallestParent->setLeft(smallest->getRight());
	}
}

//Search node
template <typename K, typename E>
bool BinaryTree<K, E>::search(K key)
{
	TNode<K, E>* toBeSearch = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;

	while (!found && toBeSearch != nullptr)
	{

		if (toBeSearch->getKey() == key)
		{
			found = true;
		}
		else
		{
			parent = toBeSearch;
			if (toBeSearch->getKey() > key)
			{
				toBeSearch = toBeSearch->getLeft();
			}
			else
			{
				toBeSearch = toBeSearch->getRight();
			}
		}
	}
	if (!found)
		return false;
}

//Adding item to Array
template <typename K, typename E>
K* BinaryTree<K, E>::toArray()
{
	K* arr = new K[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}


template <typename K, typename E>
void BinaryTree<K, E>::addItemToArray(TNode<K, E>*node, int& pos, int* arr)
{
	if (node != nullptr)
	{
		addItemToArray(node->getLeft(), pos, arr);
		arr[pos] = node->getKey();
		pos++;
		addItemToArray(node->getRight(), pos, arr);
	}
}

//Clearing root
template <typename K, typename E>
void BinaryTree<K, E>::clear()
{
	delete root;
	root = nullptr;
}

//Printing root in order
template <typename K, typename E>
void BinaryTree<K, E>::printInOrder()
{
	this->printInOrder(root);
	cout << endl;
}

template <typename K, typename E>
void BinaryTree<K, E>::printInOrder(TNode<K, E>* node)
{
	if (node != nullptr)
	{
		printInOrder(node->getLeft());
		cout << node->getKey() << " ";
		printInOrder(node->getRight());
	}
}

template <typename K, typename E>
void BinaryTree<K, E>::printPreOrder()
{
	this->printPreOrder(root);
	cout << endl;
}

template <typename K, typename E>
void BinaryTree<K, E>::printPreOrder(TNode<K, E>* node)
{
	if (node != nullptr)
	{
		cout << node->getKey() << " ";
		cout << node->getItem() << " ";
		printPreOrder(node->getLeft());
		printPreOrder(node->getRight());
	}
}

template <typename K, typename E>
void BinaryTree<K, E>::printPostOrder()
{
	this->printPostOrder(root);
	cout << endl;
}
template <typename K, typename E>
void BinaryTree<K, E>::printPostOrder(TNode<K, E>* node)
{

	if (node != nullptr)
	{
		printPostOrder(node->getLeft());
		printPostOrder(node->getRight());
		cout << node->getKey() << " ";
		cout << node->getItem() << " ";
	}
}

//Finding the depth of tree
template <typename K, typename E>
int BinaryTree<K, E>::findDepth(TNode<K, E>* node, K key)
{
	//Check if tree is empty
	if (node == NULL)
		return -1;

	//Starts from 0
	int depth = -1;
	// Check if x is current node or in left or right tree
	if ((node->getKey() == key) || (depth = findDepth(node->getLeft(), key)) >= 0 || (depth = findDepth(node->getRight(), key)) >= 0)
		return depth + 1;

	return depth;
}

template <typename K, typename E>
int BinaryTree<K, E>::findHeight(TNode<K, E>* node, K key, int& height)
{
	//Check if tree is empty
	if (node == NULL) 
		return -1;
	
	// Get height from both subtree
	int leftTree = findHeight(node->getLeft(), key, height);
	int rightTree = findHeight(node->getRight(), key, height);

	// Finding highest height of the tree
	int fHeight = max(leftTree, rightTree) + 1;

	if (node->getKey() == key)
		height = fHeight;

	return fHeight;
}

template <typename K, typename E>
int BinaryTree<K, E>::getHeight(TNode<K, E>* node, K key)
{
	// Stores height 
	int height = -1; // Height Starts from 0
	int res = findHeight(node, key, (height));

	// Return height of node
	return height;
}

template <class K, class E>
TNode<K, E>* BinaryTree<K, E>::subtree(TNode<K, E>* node, K key) {
	//Check if tree is empty
	if (node == NULL) 
		return NULL;

	//If key matches, returns node
	if (node->getKey() == key)
		return node;

	//Searches the left and right subtrees
	TNode<K, E>* leftSub = subtree(node->getLeft(), key);
	TNode<K, E>* rightSub = subtree(node->getRight(), key);

	//Returns the root of that subtree as the new tree if the key is found
	if (left_subtree != NULL)
		return left_subtree;
	

	if (right_subtree != NULL) 
		return right_subtree;
	

	//Returns NULL if no such node exists in the subtree.
	return NULL;
}