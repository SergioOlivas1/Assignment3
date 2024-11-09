#include "queue.h"

int main() {

	//create a queue and push 10 numbers into it
	Queue<int> queue;
	for (int i = 1; i <= 10; i++) {
		queue.push(i);
	}
	//display the queue
	for (int i = 0; i < queue.size(); i++) {
		int front_value = queue.front();
		cout << queue.front() << endl;
		queue.pop();
		queue.push(front_value);
	}

	return 0;
}