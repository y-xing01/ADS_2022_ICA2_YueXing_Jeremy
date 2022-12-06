#pragma once
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)
#include "TNode.h"
#include <vector>

template <typename K, typename E>
class BinaryTree
{
	void addItemToArray(TNode<K, E>* node, int& pos, int* arr);
public:
	TNode<K, E>* root;
	BinaryTree();
	void add(K key, E item);
	bool remove(K key);
	void clear();
	int count();

	void printInOrder();
	void printInOrder(TNode<K, E>* node);
	void printPreOrder();
	void printPreOrder(TNode<K, E>* node);
	void printPostOrder();
	void printPostOrder(TNode<K, E>* node);

	K* toArray();
	~BinaryTree();

	E* search(K key) {
		return nullptr;
	}
};

template <typename K, typename E>
BinaryTree<K, E>::~BinaryTree()
{
	delete root;
}

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

template <typename K, typename E>
int BinaryTree<K, E>::count()
{
	if (root == nullptr)
		return 0;
	return root->count();
}

template <typename K, typename E>
bool BinaryTree<K, E>::remove(K key)
{
	TNode<K, E>* toBeRemoved = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{

		if (toBeRemoved->getItem() == item)
		{

			found = true;
		}
		else
		{
			parent = toBeRemoved;
			if (toBeRemoved->getItem() > item)
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

template <typename K, typename E>
void BinaryTree<K, E>::clear()
{
	delete root;
	root = nullptr;
}

template <typename K, typename E>
BinaryTree<K, E>::~BinaryTree()
{
	root = nullptr;
}

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