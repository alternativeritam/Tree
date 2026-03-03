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
	
	queue<pair<Node*,pair<int,int>>> q;
	vector<vector<int>> ans;
	q.push({node,{0,0}});  // first-> vertical , second -> level
	map<int,map<int,multiset<int>>> nodes;
	while(!q.empty()){

		int len = q.size();
		for(int i=0;i<len;i++){
			Node *node = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			// store the based on level order traversal
			nodes[x][y].insert(node->data);
			if(node->left!=NULL) q.push({node->left,{x-1,y+1}});
			if(node->right!=NULL) q.push({node->right,{x+1,y+1}});

		}
	}

	for(auto v:nodes){
		vector<int> col;
		for(auto p:v.second){
			col.insert(col.end(),p.second.begin(),p.second.end());
		}
		ans.push_back(col);
	}
	

	return 0;
}
