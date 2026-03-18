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
	Node *root=node;
	int n;
	cin>>n;
	int ans=-1;
	while(node){

		if(n>node->data){
			if(node->right) node = node->right;
			else{
				node->right = new Node(n);
				break;
			}

		}
		else{
			if(node->left) node =  node->left;
			else{
				node->left = new Node(n);
				break;
			}
		}
	}	
	
	
	return 0;
}
