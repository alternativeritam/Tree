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


bool isBST(Node *node,int mn,int mx){

	if(node==NULL) return true;

	if(node->data<=mn || node->data>=mx) return false;

	return isBST(node->left,mn,node->data) && isBST(node->right,node->data,mx);
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
