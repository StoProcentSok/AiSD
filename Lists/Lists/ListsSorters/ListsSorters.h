#ifndef LISTSSORTERS_H
#define LISTSSORTERS_H
#include "../SingleLinkedLists/SinLiLists.h"

static class ListsSorters : SingleLinkedList {

private:
	int GetListLength(node* head);
	void SwapAdjacentNodes(node* first, node* second, node*& head);
	struct SingleLinkedList::node*& Merge(node* left, node* right);
	void Partition(node*& head, node*& _left, node*& _right);
	void PrintMergedParts(node* head);

public:
	void ListEveryElement(node* head);
	void BubbleSort(node*& head);
	void MergeSort(node*& head);
};

#endif
