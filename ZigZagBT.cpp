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
	queue<Node*> q;
	q.push(node);
	bool flag=false;
	vector<vector<int>> ans;

	while(!q.empty()){

		int len=q.size();
		vector<int> cur;
		for(int i=0;i<len;i++){

			Node *node = q.front();
			q.pop();

			if(node->left!=NULL) q.push(node->left);

			if(node->right!=NULL) q.push(node->right);

			cur.push_back(node->data);

		}

		if(flag) reverse(cur.begin(),cur.end());
		flag = !flag;
		ans.push_back(cur);

	}
	

	return 0;
}
