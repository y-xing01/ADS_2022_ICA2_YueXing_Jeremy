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
	TNode<K, E>* getLeftSide();
	TNode<K, E>* getRightSide();
	TNode<K, E>* getParentItem();
	void setLeftSide(TNode<K, E>* l);
	void setRightSide(TNode<K, E>* l);
	K getKey();
	E getData();
	~TNode();

	bool insert(K key, E item) {
		return false;
	}
	void setKey(K key) { this->key = key; }
	K getKey() const { return this->key; }

	void setData(E item) { this->data = item; }
	E getData() const { return this->data; }


};
