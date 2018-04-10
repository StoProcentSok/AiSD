#include <iostream>
#include "SinLiLists.h"

using namespace std;

int main() {

	SingleLinkedList lista;
	
	node Head = lista.createHead(1);

	//lista.populateWithRandom(&Head, 1, 50, 0);
	
	lista.addNodeToEnd(&Head, 2);
	lista.addNodeToEnd(&Head, 3);
	
	cout << "Length is: " << lista.getListLenght(&Head) << endl; 

	lista.showList(&Head);
	lista.showList(&Head);
	
	lista.deleteHead(*&Head);

	system("pause");

	return 0;
}



