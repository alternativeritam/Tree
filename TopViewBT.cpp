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
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	
	queue<pair<Node,int>> q;
	q.push({node,0});
	map<int,int> mp;
	vector<int> ans;
	while(!q.empty()){
		int len = q.size();
		for(int i=0;i<len;i++){
			Node *node = q.front().first;
			int level = q.front().second;
			q.pop();
			if(mp.find(level)==mp.end()) mp[level]=node->data;
			if(node->left) q.push({node->left,level-1});
			if(node->right) q.push({node->right,level+1});
		}
	}

	for(auto v:mp){
		ans.push_back(mp.second);
	}

	

	return 0;
}
