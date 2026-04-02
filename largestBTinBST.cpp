#include<bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node *left;
	Node *right;
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};


class NodeValue{

	public :

	int size;
	int mx;
	int mn;
	NodeValue(int size,int mx,int mn){
		this->size=size;
		this->mx=mx;
		this->mn=mn;
	}
};


NodeValue solve(Node *node){

	if(node==NULL) return NodeValue(0,INT_MIN,INT_MAX);

	NodeValue leftBT = solve(node->left);
	NodeValue rightBT = solve(node->right);

	if(leftBT.mx < node->data && node->data < rightBT.mn){
		return NodeValue(1+leftBT.size+rightBT.size,rightBT.mx,leftBT.mn);
	}

	return NodeValue(max(leftBT.size,rightBT.size),INT_MAX,INT_MIN);

}

int main(){

	// build the tree
	Node *node  = new Node(5);
	node->left = new Node(3);
	node->right = new Node(7);
	node->left->left = new Node(2);
	node->left->right = new Node(4);
	node->right->left = new Node(6);
	node->right->right = new Node(8);
	cout<<solve(node).size<<endl;

	
	return 0;
}
