#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
	struct Node {
		int data;
		Node* next;
	};

	Node* head;
	Node* tail;
	int size;
public:
	Queue() : head(nullptr), tail(nullptr), size(0) {}
	void push(int value) {
		Node* new_node = new Node{ value, nullptr };
		if (isEmpty()) {
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
		size++;
	}

	void push(char value) {
		Node* new_node = new Node{ value, nullptr };
		if (isEmpty()) {
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
		size++;
	}

	void pop() {
		if (isEmpty()) {
			return;
		}

		Node* temp = head;
		head = head->next;
		delete temp;

		size--;

		if (head == nullptr)
			tail = nullptr;
	}

	void print() {
		Node* current = head;
		while (current != nullptr) {
			std::cout << current->data;
			current = current->next;
		}
		std::cout << std::endl;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	int getSize() {
		return size;
	}

	int get() {
		return isEmpty() ? '\0' : head->data;
	}
	
	char getChar() {
		return isEmpty() ? '\0' : head->data;
	}

	~Queue() {
		while (!isEmpty()) {
			pop();
		}
	}
};
#endif // !QUEUE_H