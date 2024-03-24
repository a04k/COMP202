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
        return (p != nullptr) ? p->data : -1;
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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
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

    // 1. PURGE: Eliminates duplicates from the list
    void purge() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            Node* prev = current;
            Node* next = current->next;
            while (next != nullptr) {
                if (next->data == current->data) {
                    prev->next = next->next;
                    delete next;
                    next = prev->next;
                } else {
                    prev = next;
                    next = next->next;
                }
            }
            current = current->next;
        }
    }

    // 2. REVERSE: Reverses the list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // 3. insertXafterY: Inserts x after the first occurrence of y
    void insertXafterY(int x, int y) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == y) {
                Node* newNode = new Node(x);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        // y not found, insert x at the end
        insert(x, end());
    }

    // 4. concatenate: Concatenates two lists (this and another) !!this is copied
    void concatenate(LinkedList& other) {
        if (head == nullptr) {
            head = other.head;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = other.head;
    }

    // 5. split: Splits the list into two lists (odd and even)
    void split(LinkedList& odd, LinkedList& even) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data % 2 != 0) {
                odd.insert(current->data, odd.end());
            } else {
                even.insert(current->data, even.end());
            }
            current = current->next;
        }
    }

    // 6. sum: Calculates the summation of all values in the list
    int sum() {
        Node* current = head;
        int total = 0;
        while (current != nullptr) {
            total += current->data;
            current = current->next;
        }
        return total;
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
