using namespace std;
#include <iostream>
#include <vector>

struct Node {
	int data;
	Node* next;
	Node(int value) : data(value), next(nullptr) {}
};

void insertion_sort(Node*& head) {
	//Check if list is already sorted or empty
	if (!head || !head->next) {
		return;
	}

	Node* sorted = nullptr;

	//Sort list using insertion
	Node* current = head;
	while (current) {
		Node* next = current->next;
		current->next = nullptr;


		if (!sorted || current->data < sorted->data) {
			current->next = sorted;
			sorted = current;
		}
		else {
			Node* temp = sorted;
			while (temp->next && temp->next->data < current->data) {
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = next;
	}
	head = sorted;
}