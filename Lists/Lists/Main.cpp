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
	lista.PopulateWithRandom(1, 20, 20);
	lista.ShowList();

	ListsSorters sorter;
	//cout << endl << "sorting..." << endl;
	//sorter.BubbleSort(lista.head);
	//lista.ShowList();

	cout << "merge sort:" << endl;
	sorter.MergeSort(lista.head);
	lista.ShowList();
	
	
	
	system("pause");
	return 0;
}



