#include <iostream>

const int MAX_SIZE = 100; 

class Queue {
private:
  int arr[MAX_SIZE];
  int front, rear;

public:
  Queue() {
    front = -1;
    rear = -1;
  }

  bool isEmpty() {
    return front == -1 && rear == -1;
  }

  bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
  }

  void enqueue(int value) {
    if (isFull()) {
      std::cout << "Queue is full\n";
      return;
    }
    if (isEmpty()) {
      front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    arr[rear] = value;
  }

  int dequeue() {
    if (isEmpty()) {
      std::cout << "Queue is empty\n";
      return -1; 
    }
    int value = arr[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } else {
      front = (front + 1) % MAX_SIZE;
    }
    return value;
  }

  int peek() {
    if (isEmpty()) {
      std::cout << "Queue is empty\n";
      return -1; 
    }
    return arr[front];
  }
};

int main() {
  Queue queue;

  queue.enqueue(5);
  queue.enqueue(10);
  queue.enqueue(15);

  std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
  std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

  std::cout << "Front element: " << queue.peek() << std::endl;

  return 0;
}
