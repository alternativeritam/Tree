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

bool RootToNode(Node *node,vector<int> &v,int val){

	if(node==NULL) return false;

	if(node->data==val){
		v.push_back(val);
		return true;
	}

	v.push_back(node->data);

	bool left = RootToNode(node->left,v,val);

	bool right =  RootToNode(node->right,v,val);

	if(right || left) return true;

	v.pop_back();
	return false;

}


int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	// map<int,int> mp;
	// RightViewBT(node,0,mp);

	// for(auto a:mp){
	// 	cout<< a.second;
	// }

	

	return 0;
}
