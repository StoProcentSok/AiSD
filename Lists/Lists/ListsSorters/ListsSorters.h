#ifndef LISTSSORTERS_H
#define LISTSSORTERS_H
#include "../SingleLinkedLists/SinLiLists.h"

static class ListsSorters : SingleLinkedList {

private:
	int GetListLength(node *head);
	void SwapTwoNodes(node* first, node* second);

public:
	void ListEveryElement(node *head);
	void BubbleSort(node *head);

};

#endif
