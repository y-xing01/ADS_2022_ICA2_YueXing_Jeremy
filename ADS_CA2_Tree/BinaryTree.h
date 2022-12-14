#pragma once
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)
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
	BinaryTree();
	bool remove(K key);
	int count();

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

	bool search(K key);
	int getDepth(TNode<K, E>* node, K key);
	int getHeight(TNode<K, E>* node);
	bool isBalanced();
	void balanceTree(BinaryTree<K, E>& tree);
	TNode<K, E>* subtree(TNode<K, E>* node, K key);
	void printAtDepth(TNode<K, E>* root, int depth);
	void deleteNodeChildren(TNode<K, E>* root, K key);
	void printBinaryTree(TNode<K, E>* root);
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

//Getting the depth of the tree
template <typename K, typename E>
int BinaryTree<K, E>::getDepth(TNode<K, E>* node, K key)
{
	try
	{
		//Check if tree is empty
		if (node == NULL)
			return -1;

		//Starts from 0
		int depth = -1;
		// Check if x is current node or in left or right tree
		if ((node->getKey() == key) || (depth = getDepth(node->getLeft(), key)) >= 0 ||  (depth = getDepth(node->getRight(), key)) >= 0)
			return depth + 1;

		return depth;
	}
	catch (const std::exception& e)
	{
		std::cout << "An error occurred. Please try again." << std::endl;
	}
}

//Getting the height of the tree
template <typename K, typename E>
int BinaryTree<K, E>::getHeight(TNode<K, E>* node)
{
	// If the tree is empty, return 0
	if (node == NULL)
		return 0;

	// Calculate the height of the left and right subtrees of the current node
	int left_height = 0;
	int right_height = 0;

	try
	{
		// If the left subtree is not NULL, calculate its height
		if (node->getLeft() != NULL)
			left_height = getHeight(node->getLeft());

		// If the right subtree is not NULL, calculate its height
		if (node->getRight() != NULL)
			right_height = getHeight(node->getRight());
	}
	catch (const std::exception& e)
	{
		// Catch any exceptions thrown by the recursive calls to getHeight()
		// and re-throw them with a more informative error message
		throw std::runtime_error("getHeight() called on invalid tree: " + std::string(e.what()));
	}

	// Return the maximum of the two subtree heights, plus one for the current
	return std::max(left_height, right_height) + 1;
}

//Returning a new subtree
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
	if (leftSub != NULL)
		return leftSub;

	if (rightSub != NULL)
		return rightSub;

	// If the key is not found in the left or right subtree, return NULL
	return NULL;
}

//To balance the tree
template <typename K, typename E>
void balanceTree(BinaryTree<K, E>& tree)
{
	// Convert the tree to an array of keys
	int n = tree.count();
	int* arr = tree.toArray();
	const int EXCEPTION_KEY = 100;

	// Clear the tree
	tree.clear();

	// Add the keys from the array to the tree, starting with the middle key
	// and working outwards to the left and right ends of the array
	int min = 0, max = n - 1;
	while (min <= max)
	{
		int mid = (min + max) / 2;

		// Key that you want to exclude from the balanced tree. 
		// When the middle key is the exception key, the code skips that key and moves on to the next key.
		if (arr[mid] == EXCEPTION_KEY)
		{
			// Skip the middle key and move on to the next key
			min = mid + 1;
			continue;
		}

		tree.add(arr[mid], arr[mid]);
		min = mid + 1;
		max = mid - 1;
	}

	// Clean up
	delete[] arr;
}

//Check if the tree is balanced
template <typename K, typename E>
bool BinaryTree<K, E>::isBalanced()
{
	try
	{
		// Check if the tree is empty
		if (root == NULL)
			return true;

		// Check if the tree is balanced by comparing the height of the left and right subtrees
		// of the root node. Return true if they differ by at most one, or false otherwise.
		int leftHeight = getHeight(root->getLeft());
		int rightHeight = getHeight(root->getRight());
		return abs(leftHeight - rightHeight) <= 1;
	}
	catch (const std::exception& e)
	{
		// Handle the exception here
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

//Deleting Node || Children (Half Working)
template <class K, class E>
void BinaryTree<K, E>::deleteNodeChildren(TNode<K, E>* root, K key) {
	// If the tree is empty, return immediately
	if (root == nullptr) return;

	// If the current node is the one we want to remove, delete it and return
	if (root->getKey() == key)
	{
		delete root;
		return;
	}

	// Recursively search the left and right subtrees for the node to remove
	deleteNodeChildren(root->getLeft(), key);
	deleteNodeChildren(root->getRight(), key);
}

//Calculating the depth of the tree
template <class K, class E>
int calculateTreeDepth(TNode<K, E>* root) {
	// Check if the tree is empty
	if (root == NULL) {
		// If the tree is empty, return 0 as the depth
		return 0;
	}

	// Calculate the depth of the left and right subtrees
	int leftDepth = calculateTreeDepth(root->getLeft());
	int rightDepth = calculateTreeDepth(root->getRight());

	// Return the maximum depth of the left and right subtrees
	// We add 1 to account for the current node
	return max(leftDepth, rightDepth) + 1;
}

//Print at Depth (Not fully working)
template <class K, class E>
void printAtDepth(TNode<K, E>* root, int depth) {
	// Check if the tree is empty
	if (root == NULL) 
		return;

	// Calculate the depth of the tree
	int treeDepth = calculateTreeDepth(root);
	try {
		// Check if the depth argument is out of range
		if (depth < 0 || depth > treeDepth) {
			throw runtime_error("Invalid argument: " + to_string(depth));
		}

		// Print the data for the current node
		cout << root->getKey() << ", ";

		// Traverse the left and right subtrees
		printAtDepth(root->getLeft(), depth - 1);
		printAtDepth(root->getRight(), depth - 1);
	}
	catch (exception& e) {
		  cout << "Error: " << e.what() << endl;
	}
}

//Print the full tree
template <class K, class E>
void printBinaryTree(TNode<K, E>* root) {
	// Check if the tree is empty
	if (root == NULL) return;

	// Print the data for the current node
	cout << root->getKey() << ", ";

	// Recursively traverse the left and right subtrees
	printBinaryTree(root->getLeft());
	printBinaryTree(root->getRight());
}