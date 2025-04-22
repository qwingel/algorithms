#ifndef STACK_H
#define STACK_H

class Stack {
private:
	struct Node {
		int data;
		Node* next;
	};

	Node* topNode;
	int size;
public:
	Stack() : topNode(nullptr), size(0) {}
	void push(int value) {
		Node* new_node = new Node{ value, topNode };
		topNode = new_node;
		size++;
	}

	void pop() {
		if (isEmpty()) {
			return;
		}
		Node* temp = topNode;
		topNode = topNode->next;
		delete temp;
		size--;
	}

	void print() const {
		Node* current = topNode;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	bool isEmpty() {
		return topNode == nullptr;
	}

	int get() {
		return isEmpty() ? '\0' : topNode->data;
	}

	char getChar() {
		return isEmpty() ? '\0' : topNode->data;
	}

	int getSize() {
		return size;
	}

	~Stack() {
		while (!isEmpty()) {
			pop();
		}
	}
};
#endif // !STACK_H
