#ifndef LIST_H
#define LIST_H

class List {
private:
    struct Node {
        int head;
        Node* next;
    };

    Node* head;
    int size;
public:
    List() : head(nullptr), size(0) {

	}

    void append(int value) {
        Node* new_node = new Node{ value, nullptr };
        if (head == nullptr)
            head = new_node;
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
        size++;
    }

    void reverse() {
        Node* prev = nullptr;  // ���������� ����
        Node* current = head;  // ������� ����
        Node* next = nullptr;  // ��������� ����

        while (current != nullptr) {
            next = current->next;  // ��������� ��������� ����
            current->next = prev;  // ������ ����������� ���������
            prev = current;        // ���������� prev �� ������� ����
            current = next;        // ���������� current �� ��������� ����
        }

        head = prev;  // ��������� head �� ����� ��������� ����
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->head << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
	~List(){}
};
#endif
