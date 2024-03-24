#include <iostream>
#include <string>
using namespace std;

const int maxlen = 20;

struct etype {
  string name;
  int age;
};

struct stack {
  int top;
  etype elements[maxlen + 1];

  stack() {
      top = -1;
  }

  bool isEmpty() {
      return (top>maxlen);
  }

  bool isFull() {
      return top == maxlen - 1;
  }

  void push(etype element) {
    if (isFull()) {
      cout << "Stack Overflow\n";
      return;
      }
    top++;
    elements[top] = element;
  }
  void pushToBeforeTop(etype x,stack& s){
    if (s.top==1) 
      cout<<"Error stack is full";
    else{
      s.top=s.top-1;
      s.elements[s.top]=x;
    }
  }

  etype pop() {
    if (isEmpty()) {
      cout << "Stack Underflow\n";
      return {"", -1}; 
      }
    etype poppedElement = elements[top];
    top--;
    return poppedElement;
  }

  etype topElem() {
    if (isEmpty()) {
      cout << "Stack is empty\n";
      return {"", -1}; 
      }
    return elements[top];
  }
  // void display() { //this is a dumb way to implement
  //   stack tempStack = *this; 
  //   while (!tempStack.isEmpty()) {
  //     cout << "Name: " << tempStack.topElem().name << ", Age: " << tempStack.topElem().age << endl;
  //     tempStack.pop();
  //   }
  // }
};

void display(stack s) {
  while (!s.isEmpty()) {
    cout << "Name: " << s.topElem().name << ", Age: " << s.topElem().age << endl;
    s.pop();
  }
}

int main() {
  stack s;


  etype x; x.name="ahmed"; x.age=1;
  etype y; y.name="tarek" ; y.age=2;
  etype z; z.name="karam" ; z.age=3;
  etype w ; w.name="kamel"; w.age=4;
  s.push(x);
  s.push(y);
  s.push(z);
  s.push(w);

  cout<<"after pop: "<<endl;

  s.pop();
  display(s);

  return 0;
}
