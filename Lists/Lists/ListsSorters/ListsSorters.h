#ifndef LISTSSORTERS_H
#define LISTSSORTERS_H
#include "../SingleLinkedLists/SinLiLists.h"

static class ListsSorters : SingleLinkedList {

private:
	int GetListLength(node* head);
	void SwapAdjacentNodes(node* first, node* second, node*& head);
	void Merge(node* left, node* right);

public:
	void ListEveryElement(node* head);
	void BubbleSort(node*& head);
	void MergeSort(node*& head);
};

#endif
