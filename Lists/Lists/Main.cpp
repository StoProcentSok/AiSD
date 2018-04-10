#include <iostream>
#include "SinLiLists.h"

using namespace std;

int main() {

	SingleLinkedList lista;
	
	node Head = lista.createHead(1);

	//lista.populateWithRandom(&Head, 1, 50, 0);
	
	lista.addNodeToEnd(&Head, 2);
	lista.addNodeToEnd(&Head, 3);
	lista.showList(&Head);
	
	cout << "Length is: " << lista.getListLenght(&Head) << endl; 
	lista.deleteHead(&Head);
	lista.showList(&Head);
	system("pause");

	return 0;
}



