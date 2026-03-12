// using inorder and preorder

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


Node *BuildTree(vector<int> &preorder,int pre_st,int pre_en,vector<int> &inorder,int in_st,int in_en,unordered_map<int,int> &mp){

	if(pre_st>pre_en || in_st>in_en) return NULL;

	int idx = mp[preorder[pre_st]];
	int cnt = idx - in_st;
	Node *node = new Node(preorder[pre_st]);

	node->left = BuildTree(preorder,pre_st+1,pre_st+cnt,inorder,in_st,idx-1,mp);
	node->right = BuildTree(preorder,pre_st+cnt+1,pre_en,inorder,idx+1,in_en,mp);

	return node;


}

void InorderTraversal(Node *node){

	if(node==NULL) return;

	InorderTraversal(node->left);
	cout<<node->data<<" ";
	InorderTraversal(node->right);

}

int main(){

	// build the tree
	// Node *node  = new Node(1);
	// node->left = new Node(-20);
	// node->right = new Node(7);
	// node->left->left = new Node(-10);
	// node->left->right = new Node(6);
	// node->left->left->left = new Node(7);
	// cout<<CountNodes(node)<<endl;

	vector<int> inorder={40,20,50,10,60,30};
	vector<int> preorder={10,20,40,50,60,30};
	unordered_map<int,int> mp;

	for(int i=0;i<inorder.size();i++){
		mp[inorder[i]]=i;
	}

	Node *root = BuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
	InorderTraversal(root);
	return 0;
}
