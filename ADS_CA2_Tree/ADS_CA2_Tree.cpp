// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <exception>
#include <iostream>
#include <vector>
#include "Utilities.h"
#include "Car.h"
#include "Date.h"
#include "BinaryTree.h"
using namespace std;

void demoSimpleHash();
void demoDateHash();
void demoParseString();
void demoCSVToObject();
void demoPrintInOrder();
void demoPrintAtDepth();
void demoSubtree();
void demoDepthHeight();

int main()
{
	//cout << endl << "demoSimpleHash()..........." << endl;
	//demoSimpleHash();

	//cout << endl << "demoDateHash()..........." << endl;
	//demoDateHash();

	//cout << endl << "demoParseString()..........." << endl;
	//demoParseString();

	//cout << endl << "demoCSVToObject()..........." << endl;
	//demoCSVToObject();

	cout << endl << "demoPrintTree()..........." << endl;
	demoPrintInOrder();

	cout << endl << "demoPrintAtDepth()..........." << endl;
	demoPrintAtDepth();

	cout << endl << "demoSubtree()..........." << endl;
	demoSubtree();

	cout << endl << "demoDepthHeight()..........." << endl;
	demoDepthHeight();

	return 0;
}

void demoPrintInOrder() {
	// Create an instance of the BinaryTree class
	BinaryTree<int, int> tree;

	// Add some data to the tree
	tree.add(4, 4);
	tree.add(2, 2);
	tree.add(6, 6);
	tree.add(1, 1);
	tree.add(3, 3);
	tree.add(5, 5);
	tree.add(7, 7);

	cout << "Print Tree In Order: " << endl;
	printBinaryTree(tree.root);
	cout << endl;
}

void demoPrintAtDepth() {
	// Create an instance of the BinaryTree class
	BinaryTree<int, int> tree;

	// Add some data to the tree
	tree.add(4, 4);
	tree.add(2, 2);
	tree.add(6, 6);
	tree.add(1, 1);
	tree.add(3, 3);
	tree.add(5, 5);
	tree.add(7, 7);

	
	cout << "Printing Tree At Depth 1: " << endl;
	printAtDepth(tree.root, 1);

	cout << endl;
	cout << "Printing Tree At Depth 2: " << endl;
	printAtDepth(tree.root, 2);

	cout << endl;
	cout << "Printing Tree At Depth 3: " << endl;
	printAtDepth(tree.root, 3);

	cout << endl;
}

/*
	Test the subtree function to find the node
	to test this we will use the following tree
	   4
	  / \
	 2   6
	/ \ / \
   1  3 5  7
			\
			 8
*/
void demoSubtree(){
	BinaryTree<int, int> tree;
	TNode<int, int>* root = new TNode<int, int>(4, 4);
	root->setLeft(new TNode<int, int>(2, 2));
	root->setRight(new TNode<int, int>(6, 6));
	root->getRight()->setLeft(new TNode<int, int>(5, 5));
	root->getRight()->setRight(new TNode<int, int>(7, 7));
	root->getRight()->getRight()->setRight(new TNode<int, int>(8, 8));

	TNode<int, int>* root2 = tree.subtree(root, 6);

	// Check that the new tree has the expected structure
	cout << "New tree root key: " << root2->getKey() << endl;
	cout << "Left subtree key: " << root2->getLeft()->getKey() << endl;
	cout << "Right subtree key: " << root2->getRight()->getKey() << endl;
	cout << "Right subtree of 6: " << root2->getRight()->getRight()->getKey() << endl;
}

/*
	Test the depth and height function
	to test this we will use the following tree
	   4
	  / \
	 2   6
	/ \ / \
   1  3 5  7  
*/
void demoDepthHeight() {
	// Create a binary tree
	BinaryTree<int, int> tree;

	// Test findHeight method with empty tree
	int height = tree.getHeight(tree.root);
	int depth = tree.getDepth(tree.root, 1);
	cout << "Height of Tree : " << height << endl;
	cout << "Depth of Tree : " << depth << endl;

	tree.add(4, 4);
	tree.add(2, 2);
	tree.add(6, 6);
	tree.add(1, 1);
	tree.add(3, 3);
	tree.add(5, 5);
	tree.add(7, 7);

	cout << endl;
	height = tree.getHeight(tree.root);
    depth = tree.getDepth(tree.root, 1);
	cout << "Height of Tree : " << height << endl;
	cout << "Depth of Tree : " << depth << endl;
	cout << endl;
}


void demoSimpleHash() {
	//hasher for strings
	hash<string> hasherStr;
	string email = "john.smith@hotmail.com";
	cout << "hash[" << email << "]: " << hasherStr(email) << endl;

	//hasher for doubles
	hash<double> hasherDbl;
	double price = 123123.322;
	cout << "hash[" << price << "]: " << hasherDbl(price) << endl;

	//we can re-use a hasher
	double weight = 12345.9897;
	cout << "hash[" << weight << "]: " << hasherDbl(weight) << endl;

	//we can store the hash value using size_t (basically an unsigned int)
	size_t myHash = hasherStr("this is a hash value store in a uint");
	cout << myHash << endl;
}


void demoDateHash() {
	Date myDate(25, 12, 2022);
	cout << myDate << endl;
	cout << "hash[" << myDate << "]: " << myDate.hash() << endl;
}

//useful - fails when a row of data contains a field (e.g., address) which contains commas
void demoParseString()
{
	string str = "ford, 2012, 1299.55, 25/12/2022";
	string delimiter = ",";

	vector<string> rowFromCSV = splitString(str, delimiter);

	if (rowFromCSV.size() == 4)
	{
		string make = rowFromCSV[0];
		int year = stoi(rowFromCSV[1]);
		double price = stod(rowFromCSV[2]);
		vector<string> dateWords = splitString(rowFromCSV[3], "/");

		if (dateWords.size() == 3)
		{
			int date_day = stoi(dateWords[0]);
			int date_month = stoi(dateWords[1]);
			int date_year = stoi(dateWords[2]);

			Date registrationDate(date_day, date_month, date_year);
			Car myCar(make, year, price, registrationDate);

			cout << "Car: " << myCar << endl;
		}
	}
}

//best - supports rows of data that contain commas and parenthesis - thanks for Derek!
void demoCSVToObject()
{
	//note: data is a sub-folder under the folder with main CPP file
	string fileName = "data/data_4.csv";
	vector<vector<string>> allData = readDelimitedRows(fileName);

	for (vector<string> row : allData) {
		for (string field : row) {
			cout << field << ",";
		}
		cout << endl;
	}
}