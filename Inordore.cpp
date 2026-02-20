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

void Inorder(Node *node){
	if(node==NULL) return;
	Inorder(node->left);
	cout<<node->data<<endl;
	Inorder(node->right);

}

int main(){

	// build the tree
	Node *node  = new Node(1);
	Inorder(node);
	return 0;
}
