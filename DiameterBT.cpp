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


int DiameterBT(Node *node,int &mx){

	if(node==NULL) return 0;

	int left = DiameterBT(node->left,mx);
	int right = DiameterBT(node->right,mx);
	mx = max(mx,left+right);
	return 1+max(left,right);
}

int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(2);
	node->right = new Node(3);
	node->left->left = new Node(5);
	node->left->right = new Node(6);
	//node->left->left->left = new Node(7);
	int mx = INT_MIN;
	cout<<DiameterBT(node,mx)<<endl;

	return 0;
}
