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

int leftHeight(Node *node){
	int cnt=0;
	while(node){
		cnt++;
		node = node->left;
	}
	return cnt;
}

int rightHeight(Node *node){
	int cnt=0;
	while(node){
		cnt++;
		node=node->right;
	}
	return cnt;
}


int CountNodes(Node *node){

	if(node==NULL) return 0;

	int lh = leftHeight(node);
	int rh = rightHeight(node);

	if(lh==rh) return (1<<lh)-1;
	return 1+CountNodes(node->left)+CountNodes(node->right);

}


int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	cout<<CountNodes(node)<<endl;
	return 0;
}
