/*
	Dr.Wael Zakaria's Code, Written & Explained during the lecture.
*/

#include<iostream>
using namespace std;

int count=0;

class node{
	public:
	int elem;
	node* left,*right;

	node(){
	}
	node(int x,node*l, node*r){
		elem=x;
		left=l;
		right=r;
	}
};

class BST{
public:
	node* root;
	BST(){
		root=NULL;
	}
	void inorder(node* p){
		if (p==NULL)
			return;
		inorder(p->left);
		cout<<p->elem<<",";
		inorder(p->right);

	}
	void inorder(){
		inorder(root);

	}

	void insert(int x,node* &p){
		if(p==NULL)
			p=new node(x,NULL,NULL);
		else if(p->elem<x)
			insert(x,p->right);
		else if (p->elem>x)
			insert(x,p->left);
		else
			return;

	}
	void insert(int x){
		insert(x,root);

	}
	node* search(int e){
		node* p=root;
		count=0;
		while(p!=NULL){
			count++;
			if (p->elem==e)
				return p;
			else if(p->elem>e)
				p=p->left;
			else
				p=p->right;
		}
		return NULL;
	}

};

void main()
{
	BST t;
	t.insert(10);
	t.insert(40);
	t.insert(5);
	t.insert(100);
	t.insert(30);
	t.insert(7);
	t.insert(3);
	
	t.inorder();
	cout<<"\n***********************\n";
	node* p=t.search(7);
	if(p!=NULL){
		cout<<"found "<<p->elem<<":) "<<"after "<<count<<" operations";
		
	}
	else
		cout<<":("<<"after "<<count<<" operations";
	cout<<"\n***********************\n";
	p=t.search(878);
	if(p!=NULL)
		cout<<"found "<<p->elem<<":)"<<"   after "<<count<<" operations";

	else
		cout<<":("<<"after "<<count<<" operations";
	cout<<endl;

	t.inorder();
	system("pause");



}







