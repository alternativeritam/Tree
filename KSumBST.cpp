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
	Node *node  = new Node(5);
	node->left = new Node(3);
	node->right = new Node(7);
	node->left->left = new Node(2);
	node->left->right = new Node(4);
	node->right->left = new Node(6);
	node->right->right = new Node(8);
	Node *root=node;
	int k;
	cin>>k;
	Inorder(node,v);
	int n=v.size();
	int i=0;
	int j=n-1;
	while(i<j){

		if(v[i]+v[j]==k){
			cout<<"Yes"<<endl;
			break;
		}

		if(v[i]+v[j]<k){
			i++;
		}
		else{
			j--;
		}

	}

	
	return 0;
}
