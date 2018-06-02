#include <cstdlib>
#include <iostream>
#include "ListsSorters.h"

using namespace std;

int ListsSorters::GetListLength(node* head) {
	int length = 0;
	if (head != NULL) {
		length++;
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
			length++;
		}
	}
	else cout << "Head is NULL, length 0." << endl;
	return length;
}

void ListsSorters::ListEveryElement(node* head) {
	if (head != NULL) {
		node* temp = head;
		while (temp != NULL) {
			cout << "wartosc node'a: " << temp->value << endl;
			temp = temp->next;
		}
	}
}

void ListsSorters::SwapTwoNodes(node* first, node* second) {
	//dzialacy swap na liczbach:
	/*int helper = first->value;
	first->value = second->value;
	second->value = helper;*/

	node* temp1 = first;
	node* temp2 = second;
	first = temp2;
	temp2->next = temp1->next->next;

	
	

}

void ListsSorters::BubbleSort(node* head) {
	if (head != NULL) {
		node* temp = head;
		int length = GetListLength(head);
	
		cout << "Length to sort is: " << length << endl;
		for (int i = 0; i < length -1; i++)
		{
			for (int j = 0; j < length - i; j++)
			{
				if (temp->next != NULL) {
					if (temp->value > temp->next->value) {
						SwapTwoNodes(temp, temp->next);
						cout << "swapped" << endl;
					}
				}
				temp = temp->next;
			}
			temp = head;
		}
		//delete temp; <- stracone 3 godziny, rozjebuje liste, gubi heada.. :( 
	}
	else cout << "Head is NULL, nothing to sort" << endl;
}