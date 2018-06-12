
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <time.h>
#include <chrono>
#include<algorithm>
#include "SingleLinkedLIsts\SinLiLists.h"
#include "BinaryTrees\BinaryTrees.h"
#include "ListsSorters\ListsSorters.h"
#include "Graphs\Graphs.h"

using namespace std;

bool SortByWeight(const Edge &e1, const Edge &e2) {
	return (e1.weightOfWertex < e2.weightOfWertex);
}

int main() {

	int NoOfVertices, NoOfEdges;
	int _startingVertex, _endingVertex;// , _weight;

	cout << "Enter {NumberOfVertices NumberOfEdges} eg: '8 14': " << endl;
	cin >> NoOfVertices >> NoOfEdges;

	KruskalHelper k(NoOfVertices);
	Edge *e;
	e = new Edge[NoOfEdges];
	
	//KRUSKAL:
	cout << "Enter the edges: {StartingVertex EndingVertex VertexWeight} eg: '0 2 6'" << endl;
	for (int i = 0; i < NoOfEdges; i++) {
		cin >> e[i].startingVertex;
		cin >> e[i].endingVertex;
		cin >> e[i].weightOfWertex;
	}
	//next: sort the edges according to weight;
	sort(e, e + NoOfEdges, SortByWeight);

	for (int i = 0; i < NoOfEdges; i++) {
		_startingVertex = e[i].startingVertex;
		_endingVertex = e[i].endingVertex;
		if (k.FindSet(_startingVertex) != k.FindSet(_endingVertex)) {
			e[i].AddToMST(); //Changing state of edge to "inserted into MST"
			k.Union(_startingVertex, _endingVertex);
		}
	}

	cout << "Result MST: u" << endl;
	for (int i = 0; i < NoOfEdges; i++) {
		if (e[i].IsAdded)
			cout << "(" << e[i].startingVertex << " " << e[i].endingVertex << ")" <<  endl;
	}

////////Sorting Algorithms: 
	////nulling random, commented for algorithms execution time comparision, need selfsame set of "randoms".
	////srand(time(0));
	//SingleLinkedList listForMerge; //Creating first list to perform merge sort on it.
	//ListsSorters sorter;
	//listForMerge.PopulateWithRandom(1, 20, 100); //populating it with random numbers.
	//cout << "List for Merge sort, not sorted: " << endl;
	//listForMerge.ShowList();

	//cout << endl << "Merge sorting: " << "Partitioning: " <<  endl;

	//	//Record start time with chrono:
	//auto startTime = chrono::high_resolution_clock::now();
	//	//cout of partitioned part at the end of Partition() alteres time measurement.
	//sorter.MergeSort(listForMerge.head);
	//	//chrono endtime:
	//auto endTime = chrono::high_resolution_clock::now();
	//chrono::duration<double> elapsed = endTime - startTime;
	//cout << endl << endl << "Elapsed execution time: " << elapsed.count() << endl;

	//cout << "Merge sort sorted list: " << endl;
	//listForMerge.ShowList();
	//
	//cout << endl << "List for bubble sort: " << endl;
	//SingleLinkedList listForBubble;
	//listForBubble.PopulateWithRandom(1, 20, 100);
	//listForBubble.ShowList();
	//	//cout of "swapped" event in bubblesort method alteres time measurement.
	//sorter.BubbleSort(listForBubble.head);
	//cout << "Bubble sorted list: " << endl;
	//listForBubble.ShowList();
////////// end of Sorting Algorithms	
	
	system("pause");
	return 0;
}



