#ifndef TREE_H
#define TREE_H
#include "list.h"
#include <queue>

class BinaryTree {
private:
	struct Node {
		int data;
		Node* right;
		Node* left;
	};

	Node* node;
public:
	BinaryTree() : node(nullptr) {}
	int minimum() {
		while (node->left != nullptr)
			node = node->left;

		return node->data;
	}

	int maximum() {
		while (node->right != nullptr)
			node = node->right;

		return node->data;
	}

	Node* search(int target) {
		Node* currentNode = node;

		while (currentNode != nullptr) {
			if (target == currentNode->data) {
				return currentNode;
			}
			else if (target > currentNode->data) {
				currentNode = currentNode->right;
			}
			else {
				currentNode = currentNode->left;
			}
		}

		return nullptr;
	}

	void insert(int point) {
		if (node == nullptr)
			node = new Node(point);

		Node* currentNode = node;
		while (true) {
			if (point < currentNode->data) {
				if (currentNode->left == nullptr) {
					currentNode->left = new Node(point);
					return;
				}
				currentNode = currentNode->left;
			} else if (point > currentNode->data) {
				if (currentNode->right == nullptr) {
					currentNode->right = new Node(point);
					return;
				}
				currentNode = currentNode->right;
			}
			else {
				return;
			}
		}
	}

	void remove(int key) {
		if (node == nullptr)
			return;

		Node* currentNode = search(key);

		if (currentNode->left == nullptr && currentNode->right == nullptr) {
			currentNode = nullptr;
		}
		else if (currentNode->right != nullptr) {
			Node* temp = currentNode;
			currentNode = currentNode->right;
			delete temp;
		}
		else if (currentNode->left != nullptr) {
			Node* temp = currentNode;
			currentNode = currentNode->left;
			delete temp;
		}
		else {
			Node* minimum = currentNode->right;
			while (minimum->left != nullptr) {
				minimum = minimum->left;
			}

			currentNode->data = minimum->data;
			delete minimum;
		}
	}

	List breadthFirstTraversal() {
		List result;
		std::queue<Node*> queue;
		queue.push(node);

		while (!queue.empty()) {
			Node* currentNode = queue.front();
			queue.pop();

			std::cout << currentNode->data << " ";
			result.append(currentNode->data);

			if (currentNode->left != nullptr) {
				queue.push(currentNode->left);
			}
			if (currentNode->right != nullptr) {
				queue.push(currentNode->right);
			}
		}

		std::cout << std::endl;
		return result;
	}
};
#endif