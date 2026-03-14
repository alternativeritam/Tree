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


void Morristraversal(Node *node){

	vector<int> inorder;

	while(node){

		if(node->left==NULL){
			inorder.push_back(node->data);
			node = node->right;
		}

		else{
			
			Node *pre = node->left;

			while(pre->right && pre->right!=node){

				pre = pre->right;

			}

			if(pre->right==NULL){
				pre->right = node;
				node = node->left;
			}
			else{
				pre->right = NULL;
				inorder.push_back(node->data);
				node = node->right;
			}


		}

	}

	for(auto v:inorder){
		cout<<v<<" ";
	}

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
	node->left->left->left = new Node(7);
	
	Morristraversal(node);

	
	return 0;
}
