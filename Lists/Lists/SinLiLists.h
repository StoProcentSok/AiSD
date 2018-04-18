#ifndef SINLILISTS_H
#define SINLILISTS_H

#include <iostream>
using namespace std;

class SingleLinkedList {

struct node {
	int value;
	node *next; 
};

public:

	SingleLinkedList() {
		head = NULL;
	}

	void addNode(int newValue);

	static void populateWithRandom(node *H, int min, int max, int howMany);

	static void showList();

	static void addInMiddle(node *H, int newValue);
	static void addNodeBeforeHead(node *&H, int newValue);
	static void addNodeToEnd(node *H, int newValue);
	static int getListLenght(node *H);
	static void addNodeAfterNth(node *H, int nth, int newValue, bool forced);
	static void addNodeBeforeNth(node *&H, int nth, int newValue);
	static void deleteHead(node *&H);
	static void deleteLast(node *H);

private:
	node *head; // this is the private member variable. It is just a pointer to the first Node

};
#endif