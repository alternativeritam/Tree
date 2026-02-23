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


int SumBT(Node *node,int &mx){

	if(node==NULL) return 0;

	int left = SumBT(node->left,mx);
	int right = SumBT(node->right,mx);
	mx = max(mx,left+right+node->data);
	return node->data+max(left,right);
}

int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	//node->left->left->left = new Node(7);
	int mx = INT_MIN;
	cout<<SumBT(node,mx)<<endl;

	return 0;
}
