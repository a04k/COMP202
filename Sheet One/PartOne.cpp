#include <iostream>
using namespace std;

typedef int pos;
typedef int etype;

class list {
		etype* elements;
		int capacity;
		pos last;
	public:
		list(int n) {
			last = -1;
			capacity = n;
			elements = new etype[capacity];
		}
		void insert(int x, pos p) {
			if (isFull() || (p < 0 || p > last + 1)) {
				cout << "L2 ... out of Range\n";
			}
			else {
				for (int i = last; i >= p; i--) {
						elements[i + 1] = elements[i];
				}
				elements[p] = x;
				last++;
			}
		}
		void Delete(int x, pos p) {
			if (isEmpty() || (p < 0 || p > last + 1)) {
				cout << "L2 ... out of Range\n";
			}
			else{
				for (int i = p; i < last - 1; i++) {
						elements[i] = elements[i + 1];
				}
			last--;
			}
		}
		bool isEmpty() {
			return last == -1;
		}
		bool isFull() {
			return last == capacity - 1;
		}
		pos next(pos p) {
			return p + 1;
		}
		pos prev(pos p) {
			return p - 1;
		}
		pos locate(etype e) {
			for (int i = 0; i < last; i++) {
				if (e == elements[i]) {
					return i;
				}
			}
			return -1;
		}
		bool Retrieve( pos p , etype e) {
			if (p<0 || p>last) {
				return false;
			}
			e = elements[p];
			return true;
		}
		pos first() {}
		pos end() {} 
	};
  
	void main() {
		
	}