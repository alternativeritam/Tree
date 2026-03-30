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


Node *Successor(Node *node,Node *p){


	Node *ans=NULL;
	while(node!=NULL){
		if(node->data>p->data){
			ans=node;
			node = node->left;
		}
		else{
			node = node->right;
		}
	}
	return ans;

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
	vector<int> v;
	Inorder(node,v);
	cout<<v[n-1]<<endl;
	
	return 0;
}
