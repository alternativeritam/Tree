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



int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(2);
	node->right = new Node(3);
	node->left->left = new Node(5);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	queue<Node*> q;
	q.push(node);
	while(!q.empty()){
		int len = q.size();
		for(int i=0;i<len;i++){
			node = q.front();
			cout<<node->data<<" ";
			q.pop();
			if(node->left!=NULL){
				q.push(node->left);
			}
			if(node->right!=NULL){
				q.push(node->right);
			}
		}
	}

	return 0;
}
