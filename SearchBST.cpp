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


Node* Search(Node *node,int val){

	if(node==NULL) return node;

	if(node->data==val) return node;

	if(node->data>val) return Search(node->left,val);

	return Search(node->right,val);
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

	Node *ans = Search(node,4);

	if(ans==NULL){
		cout<<"No matching Node"<<endl;
	}
	else{
		cout<<ans->data<<endl;
	}

	
	

	
	return 0;
}
