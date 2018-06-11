#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <time.h>
#include <chrono>
#include "SingleLinkedLIsts\SinLiLists.h"
#include "BinaryTrees\BinaryTrees.h"
#include "ListsSorters\ListsSorters.h"

using namespace std;

int main() {
	//nulling random, commented for algorithms execution time comparision, need selfsame set of "randoms".
	//srand(time(0));
	SingleLinkedList listForMerge; //Creating first list to perform merge sort on it.
	ListsSorters sorter;
	listForMerge.PopulateWithRandom(1, 20, 100); //populating it with random numbers.
	cout << "List for Merge sort, not sorted: " << endl;
	listForMerge.ShowList();

	cout << endl << "Merge sorting: " << "Partitioning: " <<  endl;

		//Record start time with chrono:
	auto startTime = chrono::high_resolution_clock::now();
		//cout of partitioned part at the end of Partition() alteres time measurement.
	sorter.MergeSort(listForMerge.head);
		//chrono endtime:
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = endTime - startTime;
	cout << endl << endl << "Elapsed execution time: " << elapsed.count() << endl;

	cout << "Merge sort sorted list: " << endl;
	listForMerge.ShowList();
	
	cout << endl << "List for bubble sort: " << endl;
	SingleLinkedList listForBubble;
	listForBubble.PopulateWithRandom(1, 20, 100);
	listForBubble.ShowList();
		//cout of "swapped" event in bubblesort method alteres time measurement.
	sorter.BubbleSort(listForBubble.head);
	cout << "Bubble sorted list: " << endl;
	listForBubble.ShowList();
	system("pause");
	return 0;
}



