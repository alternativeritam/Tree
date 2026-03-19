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


Node *findLast(Node *node){


	while(node!=NULL && node->right!=NULL){
		node = node->right;
	}
	return node;

}


Node *helper(Node *node){

	if(node->left==NULL) return node->right;

	if(node->right==NULL) return node->left;

	Node *rightChild= node->right;
	Node *leftLast = findLast(node->left);
	leftLast->right = rightChild;
	return node->left;

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
	
	int val;
	cin>>val;

	if(node->data==val) {
		root = helper(node);
	}

	else{

		while(node){

			if(node->data>val){

				if(node->left && node->left->data==val){
					node->left = helper(node->left);

				}
				else{
					node = node->left;
				}

			}
			else{

				if(node->right && node->right->data==val){
					node->right = helper(node->right);
				}
				else{
					node = node->right;
				}

			}

		}

	}
	
	
	return 0;
}
