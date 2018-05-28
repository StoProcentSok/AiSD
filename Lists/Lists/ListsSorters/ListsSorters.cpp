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

void ListsSorters::SwitchWithNext(node* toSwitch) {
	if (toSwitch->next != NULL) {
		node* temp = toSwitch->next;
		toSwitch->next = temp->next;
		temp->next = toSwitch;
	}
}

void ListsSorters::BubbleSort(node* head) {
	if (head != NULL) {
		node* temp = head;
		int length = GetListLength(head);
		cout << "Length to sort is: " << length << endl;
		for (int i = 0; i < length - 1; i++)
		{
			while (temp->next != NULL) {
				if (temp->value > temp->next->value) {
					SwitchWithNext(temp);
				}
				temp = temp->next;
			}
		}
		
	}
	else cout << "Head is NULL, nothing to sort" << endl;
	//cout << "Length is" << GetListLength(head) << endl;
}