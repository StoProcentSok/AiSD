#ifndef SINLILISTS_H
#define SINLILISTS_H

#include <iostream>
using namespace std;

struct node {
	int value;
	node *next; 
};

class SingleLinkedList {

public:
	static node createHead(int);
	static void populateWithRandom(node *H, int min, int max, int howMany);
	static void showList(node *H);
	static void addInMiddle(node *H, int newValue);
	static void addNodeBeforeHead(node *&H, int newValue);
	static void addNodeToEnd(node *H, int newValue);
	static int getListLenght(node *H);
	static void addNodeAfterNth(node *H, int nth, int newValue, bool forced);
	static void addNodeBeforeNth(node *&H, int nth, int newValue);
	static void deleteHead(node *&H);
};
#endif