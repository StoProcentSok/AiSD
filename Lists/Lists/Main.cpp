#include <iostream>

using namespace std;

struct node {
	int value = 1;
	node* next = NULL;
};

void showList(node* H);
void addNodeBeforeHead(node *&H, int newValue);
void addNodeToEnd(node* H, int newValue);
void addNodeAfterNth(node *H, int newVale, int nth);
int getListLenght(node *H);
void addNodeAfterNth(node *H, int nth, int newValue, bool forced);
void addNodeBeforeNth(node *&H, int nth, int newValue);


int main() {

	node* Head = new node;
	
	for (int i = 2; i < 11; i++)
	{
		addNodeToEnd(Head, i);
	}
	
	cout << "Initial list: ";  showList(Head);
	addNodeBeforeNth(Head, 1, 88);
	cout << "New list: "; showList(Head);
	cout << "Length: " << getListLenght(Head) << endl;
	system("Pause");
	return 0;
}
void showList(node* H) {
	node* p = H;
	cout << "H : ";
		while (p != NULL) {
		cout << p->value << " -> ";
		p = p->next;
	}
	cout << "NULL" << endl;
}
void addNodeBeforeHead(node *&H, int newValue) {
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
void addNodeToEnd(node* H, int newValue) {
	node *p = new node;
	p = H;
	while (p->next != NULL)
		p = p->next;
	node *newLastNode = new node;
	newLastNode->value = newValue;
	newLastNode->next = NULL;
	p->next = newLastNode;
	
}
int getListLenght(node *H) {
	node *p = new node;
	p = H;
	int counter = 0;
	if (H != NULL) {
		counter++;
		while (p->next != NULL) {
			counter++;
			p = p->next;
		}
	}
	return counter;
}
void addNodeAfterNth(node *H, int nth, int newValue, bool forced) {
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
void addNodeBeforeNth(node *&H, int nth, int newValue) {
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
				newNode->next = p ->next;
				p->next = newNode;
			}
		}
		else
			cout << "nth has to be greater than 0.";
	}
	else
		cout << "nth is bigger than list length!";
	
}


