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

void Preorder(Node *node){
	if(node==NULL) return;
	cout<<node->data<<endl;
	Preorder(node->left);
	Preorder(node->right);

}

int main(){

	// build the tree
	Node *node  = new Node(1);
	Preorder(node);
	return 0;
}
