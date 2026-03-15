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

Node *find(Node *node){

	while(node->right!=NULL){
		node = node->right;
	}
	return node;
}

Node *flatten(Node *node){

	if(node==NULL) return node;
	
	Node *lf = flatten(node->left);
	Node *temp = node->right;
	if(lf!=NULL){
		node->right=lf;
		Node *last = find(lf);
		last->right = flatten(temp);
	}
	else{
		node->right=flatten(temp);
	}
	node->left=NULL;
	return node;
}




void InorderTraversal(Node *node){

	if(node==NULL) return;

	InorderTraversal(node->left);
	cout<<node->data<<" ";
	InorderTraversal(node->right);

}

int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(8);
	
	Node *new_node = flatten(node);
	Node *curr = new_node;
	while(curr != NULL){
	    cout << curr->data << " ";
	    curr = curr->right;
	}

	
	return 0;
}
