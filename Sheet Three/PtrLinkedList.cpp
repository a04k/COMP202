#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int x, Node* p = nullptr) {
        Node* newNode = new Node(x);
        if (p == nullptr) {
            newNode->next = head;
            head = newNode;
        }
        else {
            newNode->next = p->next;
            p->next = newNode;
        }
    }

    Node* locate(int x) {
        Node* current = head;
        while (current != nullptr && current->data != x) {
            current = current->next;
        }
        return current;
    }

    int retrieve(Node* p) {
        return (p != nullptr) ? p->data : -1; // Adjust as per your requirements
    }

    void remove(Node* p) {
        if (p != nullptr) {
            if (p == head) {
                head = p->next;
            }
            else {
                Node* current = head;
                while (current != nullptr && current->next != p) {
                    current = current->next;
                }
                if (current != nullptr) {
                    current->next = p->next;
                }
            }
            delete p;
        }
    }

    Node* next(Node* p) {
        return (p != nullptr) ? p->next : nullptr;
    }

    Node* previous(Node* p) {
        if (p != nullptr && p != head) {
            Node* current = head;
            while (current != nullptr && current->next != p) {
                current = current->next;
            }
            return current;
        }
        else {
            return nullptr;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Node* first() {
        return head;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node* end() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
        return current;
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    ~LinkedList() { //destructor (m5dnhash fl class joke)
        clear();
    }
};

int main() {
    LinkedList myList;

    myList.insert(1, myList.end());
    myList.insert(2, myList.end());
    myList.insert(3, myList.end());

    myList.print();

    Node* position = myList.locate(2);
    cout << "Element at position 2: " << myList.retrieve(position) << endl;

    myList.remove(position);

    myList.print();

    cout << "Size of the list: " << myList.size() << endl;

    return 0;
}
