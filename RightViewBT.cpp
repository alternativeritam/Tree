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

void RightViewBT(Node *node,int level,map<int,int> &mp){

	if(node==NULL) return;

	if(mp.find(level)==mp.end()) mp[level]=node->data;

	RightViewBT(node->right,level+1,mp);
	RightViewBT(node->left,level+1,mp);
}



int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	map<int,int> mp;
	RightViewBT(node,0,mp);

	for(auto a:mp){
		cout<< a.second;
	}

	

	return 0;
}
