#pragma once
#include <list>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
	Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue
{
private:
	Node<T>* head;
	Node<T>* tail;
	int num_items;

public:
	Queue();// Constructor
	~Queue();// Destructor
	void push(const T& value);
	void pop();
	T front() const;
	int size() const;
	bool empty() const;
	void move_to_rear();
};

// Constructor
template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template <typename T>
Queue<T>::~Queue() {
	while (!empty()) {
		pop();
	}
}

//add an element to the end of the queue
template<typename T>
inline void Queue<T>::push(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	if (tail) {
		tail->next = newNode;
	}
	else {
		head = newNode;
	}
	tail = newNode;
	++num_items;
}

//take out front element from the queue
template<typename T>
inline void Queue<T>::pop()
{
	if (empty()) {
		cout << "cannot pop, queue is empty" << endl;
		return;
	}
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	--num_items;
	if (!head) { 
		tail = nullptr;
	}
}

//view the element at the front of the queue
template<typename T>
inline T Queue<T>::front() const
{
	if (empty()) {
		throw runtime_error("Queue is empty, cannot access front.");
	}
	return head->data;
}

//return the number of elements in the queue
template<typename T>
inline int Queue<T>::size() const
{
	return num_items;
}

//check if the queue is empty
template<typename T>
inline bool Queue<T>::empty() const
{
	return num_items == 0;
}

//move an element from the front of the queue to the back
template<typename T>
inline void Queue<T>::move_to_rear()
{
	if (size() <= 1) return;
	T front_value = front();
	pop();
	push(front_value);
}
