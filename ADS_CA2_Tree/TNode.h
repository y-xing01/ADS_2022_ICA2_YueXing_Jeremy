#pragma once

template <typename K, typename E>
class TNode {
private:
	/// <summary>
	/// A subset of the main data used to generate a unique number for the node
	/// </summary>
	K key;
	/// <summary>
	/// The actual data that the node stores e.g. Person, Record, Student
	/// </summary>
	E item;

	/// <summary>
	/// Pointers to the two kids. Go left if new data key < key for this node, else go right
	/// </summary>
	TNode* pLeft, * pRight;
	TNode* parentItem;

public:
	TNode();
	TNode(K key, E item);
	void setItem(K key, E item);
	int countItem();
	void add(K key, E item);
	TNode<K, E>* getLeft();
	TNode<K, E>* getRight();
	void setLeft(TNode<K, E>* l);
	void setRight(TNode<K, E>* l);
	TNode<K, E>* getParentItem();
	K getKey();
	E getItem();
	~TNode();

	bool insert(K key, E item) {
		return false;
	}
	void setKey(K key) { this->key = key; }
	K getKey() const { return this->key; }

	void setData(E item) { this->data = item; }
	E getData() const { return this->data; }
};

template <typename K, typename E>
TNode<K, E>::~TNode()
{
	delete left;
	delete right;
}

template <typename K, typename E>
K TNode<K, E>::getKey()
{
	return this->key;
}

template <typename K, typename E>
E TNode<K, E>::getItem()
{
	return this->item;
}

template <typename K, typename E>
void TNode<K, E>::setItem(K key, E item)
{
	this->key = key;
	this->item = item;
}

template <typename K, typename E>
void TNode<K, E>::add(K keyItem, E item)
{
	if (keyItem == this->key)
	{
		return;
	}
	else if (keyItem < this->key)
	{
		if (left == nullptr)
		{
			left = new TNode<K, E>(keyItem, item);
		}
		else
		{
			left->add(keyItem, item);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new TNode<K, E>(keyItem, item);
			right->data = keyItem;
			right->parentItem = this;
		}
		else
		{
			right->add(keyItem, item);
		}
	}
}

template <typename K, typename E>
TNode<K, E>::TNode()
{
	parentItem = nullptr;
	left = nullptr;
	right = nullptr;
}

template <typename K, typename E>
TNode<K, E>::TNode(K key, E item)
{
	parentItem = nullptr;
	left = nullptr;
	right = nullptr;
	this->key = key;
	this->item = item;
}

template <typename K, typename E>
int TNode<K, E>::countItem()
{
	int amount = 1;
	if (left != nullptr)
	{
		amount += left->count();
	}
	if (right != nullptr)
	{
		amount += right->count();
	}
	return amount;
}

template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getLeft()
{
	return this->left;
}

template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getRight()
{
	return this->right;
}

template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getParentItem()
{
	return this->parentItem;
}

template <typename K, typename E>
void TNode<K, E>::setLeft(TNode<K, E>* left)
{
	this->left = left;
}

template <typename K, typename E>
void TNode<K, E>::setRight(TNode<K, E>* right)
{
	this->right = right;
}