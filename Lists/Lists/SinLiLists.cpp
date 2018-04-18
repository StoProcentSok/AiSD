#include "SinLiLists.h"


//node SingleLinkedList::createHead(int headValue){
//	node* Head = new node;
//	Head->value = headValue;
//	Head->next = NULL;		
//	return &Head;
//}



void SingleLinkedList::showList() {
	
}

void SingleLinkedList::addNode(int newValue) {
	node* n = new node();
	n->value = newValue;
	n->next = NULL;

	if(head == NULL)
	head = n;
}

void SingleLinkedList::addNodeBeforeHead(node *&H, int newValue) {
	node *newFirstNode = new node;
	newFirstNode->value = newValue;
	if (H == NULL) {
		newFirstNode->next = NULL;
		H = newFirstNode;
	}
	else {
		newFirstNode->next = H;
		H = newFirstNode;
	}
}

void SingleLinkedList::addNodeToEnd(node* H, int newValue) {
	node *p = new node;
	p = H;
	while (p->next != NULL)
		p = p->next;
	node *newLastNode = new node;
	newLastNode->value = newValue;
	newLastNode->next = NULL;
	p->next = newLastNode;

}
int SingleLinkedList::getListLenght(node *H) {
	node *p = new node;
	p = H;
	int counter = 0;
	if (p != NULL) {
			while (p != NULL) {
				counter++;
				p = p->next;
			}
	}
	return counter;
}

void SingleLinkedList::addNodeAfterNth(node *H, int nth, int newValue, bool forced) {
	//parametr 'forced' decyduje czy w zbyt krotkiej liscie wymuszamy dodanie
	//elementu na jej koncu czy w danym przypadku nie dodajemy elementu wcale.
	node *p = new node;
	p = H;
	if (nth > 0) {
		if (forced == true) {
			if (getListLenght(H) == nth) {
				//dodawanie na koncu listy, 'nth' jest ostatnim elementem.
				addNodeToEnd(H, newValue);
			}
			else if (getListLenght(H) > nth) {
				//zwykle dodawanie w trakcie listy, 'nth' jest mniejszy niz dlugosc listy.
				for (int i = 1; i < nth; i++)
				{
					p = p->next;
				}
				node *newNode = new node;
				newNode->value = newValue;
				newNode->next = p->next;
				p->next = newNode;
			}
			else if (getListLenght(H) < nth) {
				//bool forced - true, dodajemy do za krotkiej listy, wstawiamy na koniec.
				addNodeToEnd(H, newValue);
			}
		}
		if (forced == false) {
			if (getListLenght(H) == nth) {
				addNodeToEnd(H, newValue);
			}
			else if (getListLenght(H) > nth) {
				for (int i = 1; i < nth; i++)
				{
					p = p->next;
				}
				node *newNode = new node;
				newNode->value = newValue;
				newNode->next = p->next;
				p->next = newNode;
			}
			else if (getListLenght(H) < nth) {
				cout << "List does not have sufficeint ammount of nodes, can't add node after " << nth << "'th node" << endl;
				cout << "You can try to run this function with 'force' parameter set to true" << endl;
			}

		}
	}
	else
		cout << "Nth has to be greater than 0.";
}
//TODO:
void SingleLinkedList::addNodeBeforeNth(node *&H, int nth, int newValue) {
	if (nth <= getListLenght(H)) {
		if (nth > 0) {
			if (nth == 1) {
				addNodeBeforeHead(H, newValue);
			}
			else {
				//Tutaj pozostanie kazdy inny wlasciwy przypadek, 
				//czyli 'nth' w srodku lub maks na koncu listy.
				node *p = new node;
				p = H;
				for (int i = 1; i < nth; i++)
				{
					p = p->next;
				}
				node *newNode = new node;
				newNode->next = p->next;
				p->next = newNode;
			}
		}
		else
			cout << "nth has to be greater than 0.";
	}
	else
		cout << "nth is bigger than list length!";

}

void SingleLinkedList::addInMiddle(node *H, int newValue) {
	node *p = H;
	if (p != NULL) {
		if (SingleLinkedList::getListLenght(p) >= 2) {
			SingleLinkedList::addNodeAfterNth(p, (SingleLinkedList::getListLenght(p) / 2), newValue, true);
		}
		else if (SingleLinkedList::getListLenght(p) == 2) {
			SingleLinkedList::addNodeAfterNth(p, 1, newValue, true);
		}
		else if (SingleLinkedList::getListLenght(p) == 1) {
			cout << "Nie moge dodac wartosci, lista jest jednoelementowa!" << endl;
		}
	}
}

void SingleLinkedList::populateWithRandom(node *H, int min, int max, int howMany) {
	node* p = H;
	for (int i = 1; i < howMany; i++) {
		int newValue = rand()% max + min;
		SingleLinkedList::addNodeToEnd(p, newValue);
	}
}

void SingleLinkedList::deleteLast(node *H) {
	node* p = H;
	while (p != NULL) {
		while (p->next->next != NULL) {
			p = p->next;
		}
	}
	delete  p->next->next;
	p->next = NULL;
}

void SingleLinkedList::deleteHead(node *&H) {
	//TODO warunki brzegowe
	node *temp = H->next;
	H = temp;
}
//TODO: usun ostatni, usun n-ty