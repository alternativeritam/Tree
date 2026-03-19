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


void Inorder(Node *node,vector<int> &v){

	if(node==NULL) return

	Inorder(node->left,v);
	v.push_back(node->data);
	Inorder(node->right,v);
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
	Node *root=node;
	int n;
	cin>>n;
	vector<int> v;
	Inorder(node,v);
	cout<<v[n-1]<<endl;
	
	return 0;
}
