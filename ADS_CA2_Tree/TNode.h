#pragma once

template <typename K, typename E>
class TNode {
private:
	// Main data used to generate a unique number for the node
	K key;
	// Data that the node stores e.g. Person, Record, Student
	E item;
	// Pointers to the two kids. Go left if new data key < key for this node, else go right
	TNode* left, * right;
	TNode* parent;

public:
	TNode();
	TNode(K key, E item);
	void setData(K key, E item);
	int count();
	void add(K key, E item);
	TNode<K, E>* getLeft();
	TNode<K, E>* getRight();
	void setLeft(TNode<K, E>* left);
	void setRight(TNode<K, E>* right);
	TNode<K, E>* getParent();
	K getKey();
	E getItem();
	~TNode();

	bool insert(K key, E item) {
		return false;
	}
	void setKey(K key) { this->key = key; }
	K getKey() const { return this->key; }

	void setItem(E item) { this->item = item; }
	E getItem() const { return this->item; }
};

template <typename K, typename E>
TNode<K, E>::~TNode()
{
	delete left;
	delete right;
}

template <typename K, typename E>
TNode<K, E>::TNode()
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

template <typename K, typename E>
TNode<K, E>::TNode(K key, E item)
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	this->key = key;
	this->item = item;
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
void TNode<K, E>::setData(K key, E item)
{
	this->key = key;
	this->item = item;
}


template <typename K, typename E>
void TNode<K, E>::add(K key, E item)
{
	if (key == this->key)
	{
		return;
	}
	else if (key < this->key)
	{
		if (left == nullptr)
		{
			left = new TNode<K, E>(key, item);
		}
		else
		{
			left->add(key, item);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new TNode<K, E>(key, item);
			right->item = key;
			right->parent = this;
		}
		else
		{
			right->add(key, item);
		}
	}
}



template <typename K, typename E>
int TNode<K, E>::count()
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
TNode<K, E>* TNode<K, E>::getParent()
{
	return this->parent;
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