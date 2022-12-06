#pragma once
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <typename K, typename E>
class BinaryTree
{
public:
	TNode<K, E>* root;
	BinaryTree();
	void add(K item, E item);
	bool remove(K item, E item);
	void clear();
	int count();

	E* search(K key) {
		return nullptr;
	}
};

template <typename K, typename E>
BinaryTree<K, E>::BinaryTree()
{
	root = nullptr;
}
