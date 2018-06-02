#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <time.h>
#include "SingleLinkedLIsts\SinLiLists.h"
#include "BinaryTrees\BinaryTrees.h"
#include "ListsSorters\ListsSorters.h"

using namespace std;

int main() {
	srand(time(0));
	SingleLinkedList lista;
	/*lista.AddNode(2);
	lista.AddNode(1);
	lista.AddNode(6);
	lista.AddNode(3);*/
	
	lista.PopulateWithRandom(1, 20, 20);
	lista.ShowList();
	
	ListsSorters sorter;
	cout << endl << "sorting..." << endl;

	sorter.BubbleSort(lista.head);
	lista.ShowList();
	
	//BinaryTree tree;
	
	
	system("pause");

	return 0;
}



