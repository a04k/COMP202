#include <iostream>
#include <vector>

struct Node {
  int data;
  std::vector<Node*> children;

  Node(int value) {
    data = value;
  }
};

class Tree {
private:
  Node* root;

  void destroyTree(Node* node) {
    if (node != nullptr) {
      for (Node* child : node->children) {
        destroyTree(child);
      }
      delete node;
    }
  }

public:
  Tree() {
    root = nullptr;
  }

  ~Tree() {
    destroyTree(root);
  }

  Node* createNode(int value) {
    return new Node(value);
  }

  Node* getRoot() {
    return root;
  }

  void insert(int parentValue, int value) {
    Node* newNode = createNode(value);
    if (parentValue == -1) {
      root = newNode;
    } else {
      Node* parent = findNode(root, parentValue);
      if (parent != nullptr) {
        parent->children.push_back(newNode);
      } else {
        std::cout << "Parent not found\n";
        delete newNode;
      }
    }
  }

  Node* findNode(Node* node, int value) {
    if (node == nullptr)
      return nullptr;
    if (node->data == value)
      return node;
    for (Node* child : node->children) {
      Node* found = findNode(child, value);
      if (found != nullptr)
        return found;
    }
    return nullptr;
  }
};

int main() {
  Tree tree;

  tree.insert(-1, 1); // Insert 1 as root
  tree.insert(1, 2);  // Insert 2 as child of 1
  tree.insert(1, 3);  // Insert 3 as child of 1
  tree.insert(2, 4);  // Insert 4 as child of 2
  tree.insert(3, 5);  // Insert 5 as child of 3
  tree.insert(3, 6);  // Insert 6 as child of 3

  return 0;
}
