#include <cstdlib>
#include <iostream>
#include <chrono> //timer, clock
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

void ListsSorters::SwapAdjacentNodes(node* first, node* second, node*& head) {
	//dzialajacy swap na :
	/*int helper = first->value;
	first->value = second->value;
	second->value = helper;*/

	if (first == head) {
		node* temp1 = first;
		node* temp2 = second;
		temp1->next = temp2->next;
		head = temp2;
		head->next = temp1;
	}
	else
	{
		node* temp;
		node* temp1;
		node* temp2;
		temp = head;
		while (temp->next != first) {
			temp = temp->next;
		}
		temp1 = temp; //wskazuje przed 1
		temp2 = temp->next->next; //wskazuje na 2
		first->next = temp2->next;
		temp->next = temp2;
		temp2->next = first;
	}
	
	cout << "swapped" << endl;
	//TODO: Wrocic do proby swapowania bez wskazywania na elementy poprzednie.
	

}

void ListsSorters::BubbleSort(node*& head) {
	//Record start time with chrono:
	auto startTime = chrono::high_resolution_clock::now(); //c++11 auto keyworad instead of chrono std::chrono::time_point<std::chrono::high_resolution_clock> type
	
	bool swap = true;
	while (swap == true) {
		swap = false;
		node* temp = head;
		while (temp != NULL && temp->next != NULL) {
			if (temp->value > temp->next->value) {
				SwapAdjacentNodes(temp, temp->next, *&head);
				swap = true;
			}
			temp = temp->next;
		}
	}

	/*else cout << "Nothing to sort!" << endl;*/
	//chrono endtime:
	auto endTime = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = endTime - startTime;

	cout << "Elapsed execution time: " << elapsed.count() << endl;
}

void ListsSorters::Merge(node* left, node* right) {

}

void ListsSorters::MergeSort(node*& head) {

}