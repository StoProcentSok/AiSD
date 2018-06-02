#include <cstdlib>
#include <iostream>
#include "SinLiLists.h"

using namespace std;

SingleLinkedList::SingleLinkedList() {
	head = NULL;
	current = NULL;
}

void SingleLinkedList::AddNode(int newValue) {
	node* n = new node;
	n->next = NULL;
	n->value = newValue;

	if (head != NULL) {
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = n;
	}
	else {
		head = n;
	}
}

void SingleLinkedList::DeleteLast() {
	if (head != NULL) {
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		delete current;
	}
	else {
		cout << "List is empty, nothing to delete" << endl;
	}
}

void SingleLinkedList::ShowList() {
	if (head != NULL) { 
		cout << "head: " << head->value << endl;
		current = head;
		cout << "List: " << head->value;
		//if (current->next != NULL) {
			while (current->next != NULL) {
				cout << "->" << current->next->value;
				current = current->next;
			}
			
		//}
		cout << "->(NULL)" << endl;
	}
	else
		cout << "Head is NULL" << endl;
}

int SingleLinkedList::GetListLength() {
	int length = 0;
	if (head != NULL) {
		current = head;
		length = 1;
		while (current->next != NULL) {
			current = current->next;
			length++;
		}
		cout << "List length is " << length << endl;
	}
	else
		cout << "Head is null, length 0" << endl;
	return length;
}

void SingleLinkedList::PopulateWithRandom(int min, int max, int howMany) {
	if (head != NULL) {
		cout << "Can't populate with random, list is not empty!" << endl;
	}
	else {
		for (int i = 1; i < howMany + 1; i++) {
			int newValue = rand() % max + min;
			SingleLinkedList::AddNode(newValue);
		}
		//Ostatni element to NULL, metoda addNode zapewnia dodanie node'a w ktorym ->next = NULL.
	}
}

void SingleLinkedList::AddNodeBeforeHead(int newValue) {
	if (head != NULL) {
		node* temp = head;
		node* newNode = new node;
		newNode->value = newValue;
		newNode->next = temp;
		SingleLinkedList::head = newNode;
	}
	else {
		cout << "List is empty, initialize value(s) first!" << endl;
	}
}

void SingleLinkedList::DeleteHead() {
	if (head != NULL) {
		current = head;
		if (current->next == NULL) {
			delete current;
			cout << head->value;
		}
		else {
			current = head->next;
			delete head;
			head = current;
		}
	}
	else {
		cout << "Head is null, can't delete it tho!";
	}
}

void SingleLinkedList::SwitchFirstAndLast() {
	if (head != NULL) {
		if (head->next != NULL) {
			node* tempHead = head;
			current = head;
			while (current->next->next != NULL) {
				current = current->next;
			}
			node* temp = current;
			tempHead->next = 
			
			//node* temp = current; //container wskazuje na przedostatni element
			
			
		}
		else
			cout << "List contains only head node, can't switch." << endl;
	}
	else
		cout << "Head is null, nothing to switch!" << endl;
}



//void SingleLinkedList::addNodeAfterNth(node *H, int nth, int newValue, bool forced) {
//	//parametr 'forced' decyduje czy w zbyt krotkiej liscie wymuszamy dodanie
//	//elementu na jej koncu czy w danym przypadku nie dodajemy elementu wcale.
//	node *p = new node;
//	p = H;
//	if (nth > 0) {
//		if (forced == true) {
//			if (getListLenght(H) == nth) {
//				//dodawanie na koncu listy, 'nth' jest ostatnim elementem.
//				addNodeToEnd(H, newValue);
//			}
//			else if (getListLenght(H) > nth) {
//				//zwykle dodawanie w trakcie listy, 'nth' jest mniejszy niz dlugosc listy.
//				for (int i = 1; i < nth; i++)
//				{
//					p = p->next;
//				}
//				node *newNode = new node;
//				newNode->value = newValue;
//				newNode->next = p->next;
//				p->next = newNode;
//			}
//			else if (getListLenght(H) < nth) {
//				//bool forced - true, dodajemy do za krotkiej listy, wstawiamy na koniec.
//				addNodeToEnd(H, newValue);
//			}
//		}
//		if (forced == false) {
//			if (getListLenght(H) == nth) {
//				addNodeToEnd(H, newValue);
//			}
//			else if (getListLenght(H) > nth) {
//				for (int i = 1; i < nth; i++)
//				{
//					p = p->next;
//				}
//				node *newNode = new node;
//				newNode->value = newValue;
//				newNode->next = p->next;
//				p->next = newNode;
//			}
//			else if (getListLenght(H) < nth) {
//				cout << "List does not have sufficeint ammount of nodes, can't add node after " << nth << "'th node" << endl;
//				cout << "You can try to run this function with 'force' parameter set to true" << endl;
//			}
//
//		}
//	}
//	else
//		cout << "Nth has to be greater than 0.";
//}
////TODO:
//void SingleLinkedList::addNodeBeforeNth(node *&H, int nth, int newValue) {
//	if (nth <= getListLenght(H)) {
//		if (nth > 0) {
//			if (nth == 1) {
//				addNodeBeforeHead(H, newValue);
//			}
//			else {
//				//Tutaj pozostanie kazdy inny wlasciwy przypadek, 
//				//czyli 'nth' w srodku lub maks na koncu listy.
//				node *p = new node;
//				p = H;
//				for (int i = 1; i < nth; i++)
//				{
//					p = p->next;
//				}
//				node *newNode = new node;
//				newNode->next = p->next;
//				p->next = newNode;
//			}
//		}
//		else
//			cout << "nth has to be greater than 0.";
//	}
//	else
//		cout << "nth is bigger than list length!";
//
//}
//
//void SingleLinkedList::addInMiddle(node *H, int newValue) {
//	node *p = H;
//	if (p != NULL) {
//		if (SingleLinkedList::getListLenght(p) >= 2) {
//			SingleLinkedList::addNodeAfterNth(p, (SingleLinkedList::getListLenght(p) / 2), newValue, true);
//		}
//		else if (SingleLinkedList::getListLenght(p) == 2) {
//			SingleLinkedList::addNodeAfterNth(p, 1, newValue, true);
//		}
//		else if (SingleLinkedList::getListLenght(p) == 1) {
//			cout << "Nie moge dodac wartosci, lista jest jednoelementowa!" << endl;
//		}
//	}
//}
//

//
//void SingleLinkedList::deleteLast(node *H) {
//	node* p = H;
//	while (p != NULL) {
//		while (p->next->next != NULL) {
//			p = p->next;
//		}
//	}
//	delete  p->next->next;
//	p->next = NULL;
//}
//
//void SingleLinkedList::deleteHead(node *&H) {
//	//TODO warunki brzegowe
//	node *temp = H->next;
//	H = temp;
//}
//TODO: usun n-t