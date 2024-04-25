#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree {
private:
	Node* root;

	void destroyTree(Node* node) {
		if (node != NULL) {
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
	}

public:
	BinaryTree() {
		root = NULL;
	}

	~BinaryTree() {
		destroyTree(root);
	}

	Node* getRoot() {
		return root;
	}

	Node* createNode(int value) {
		return new Node(value);
	}

	void insert(int value) {
		if (root == NULL) {
			root = createNode(value);
			return;
		}

		Node* current = root;
		Node* parent = NULL;

		while (current != NULL) {
			parent = current;
			if (value < current->data) {
				current = current->left;
			} else {
				current = current->right;
			}
		}

		if (value < parent->data) {
			parent->left = createNode(value);
		} else {
			parent->right = createNode(value);
		}
	}

};

int main() {
	BinaryTree tree;

	tree.insert(50);
	tree.insert(30);
	tree.insert(70);
	tree.insert(20);
	tree.insert(40);
	tree.insert(60);
	tree.insert(80);


	return 0;
}
