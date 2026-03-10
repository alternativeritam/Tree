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




void ParentTrack(Node *node,unordered_map<Node*,Node*> &mp){

	queue<Node*> q;
	q.push(node);

	while(!q.empty()){

		int len = q.size();
		for(int i=0;i<len;i++){

			Node *cur = q.front();
			q.pop();

			if(cur->left){
				mp[cur->left]=cur;
				q.push(cur->left);
			} 

			if(cur->right){
				mp[cur->right]=cur;
				q.push(cur->right);
			}

		}

	}

}


int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	unordered_map<Node*,Node*> mp;
	ParentTrack(node,mp);
	Node *target=node->left->right;

	int ans=0;
	queue<Node*> q;
	q.push(target);
	unordered_map<Node*,bool> visited;
	visited[target]=true;

	while(!q.empty()){

		int len=q.size();
		bool flag=false;
		for(int i=0;i<len;i++){
			Node *cur=q.front();
			q.pop();

			if(cur->left && !visited[cur->left]){
				q.push(cur->left);
				visited[cur->left]=true;
				flag=true;
			}
			if(cur->right && !visited[cur->right]){
				q.push(cur->right);
				visited[cur->right]=true;
				flag=true;
			}
			if(mp.find(cur)!=mp.end() && !visited[mp[cur]]){
				q.push(mp[cur]);
				visited[mp[cur]]=true;
				flag=true;
			}
		}
		if(flag) ans++;

	}

	cout<<ans<<endl;

	return 0;
}
