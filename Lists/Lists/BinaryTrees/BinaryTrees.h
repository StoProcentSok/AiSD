#ifndef BINARYTREES_H
#define BINARYTREES_H

class BinaryTree {

private:
	struct node {
		int value;
		node* left;
		node* right;
	};

	node* root;
	node* current;

public:
	BinaryTree();

	void AddNode(int newValue);
	void IsLeaf(int ValueToCHeck);
};

#endif
