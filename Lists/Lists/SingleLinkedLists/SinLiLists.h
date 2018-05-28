#ifndef SINLILISTS_H
#define SINLILISTS_H

#include <iostream>


class SingleLinkedList {

public:

	struct node {
		int value;
		node* next;
	};

	SingleLinkedList();
		
	void AddNode(int newValue);
	void DeleteLast();
	void ShowList();
	int GetListLength();
	void PopulateWithRandom(int min, int max, int howMany);
	void AddNodeBeforeHead(int newValue);
	void DeleteHead();
	void SwitchFirstAndLast();

	//Head oraz current przeniesione do publicznych, aby moc odniesc sie do nich z zewnetrznej
	//dziedziczacej klasy ListsSorters zawierajacej metody statyczne, ktore beda odnosic sie do
	//listy wlasnie przez ujawnione pole head.
	node* head;
	node* current;
private:

	 //node* head // Private member variable. Just a pointer to the first Node of object. 
	

	/*static void addInMiddle(node *H, int newValue);
	static void addNodeToEnd(node *H, int newValue);
	static void addNodeAfterNth(node *H, int nth, int newValue, bool forced);
	static void addNodeBeforeNth(node *&H, int nth, int newValue);
	*/
};

#endif