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


int BalanceBT(Node *node){

	if(node==NULL) return 0;

	int left = BalanceBT(node->left);
	int right = BalanceBT(node->right);
	if(left==-1 || right==-1) return -1;
	if(abs(left-right)>1) return -1;
	return 1+max(left,right);
}


int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(2);
	node->right = new Node(3);
	node->left->left = new Node(5);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	cout<<BalanceBT(node)<<endl;

	return 0;
}
