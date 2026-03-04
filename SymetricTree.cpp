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

bool isSymetric(Node *left,Node *right){

	if(left==NULL || right==NULL) return left==right;

	if(left->data!=right->data) return false;

	return isSymetric(left->left,right->right) && 
			isSymetric(left->right,right->left);

}




int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	// map<int,int> mp;
	// RightViewBT(node,0,mp);

	// for(auto a:mp){
	// 	cout<< a.second;
	// }

	

	return 0;
}
