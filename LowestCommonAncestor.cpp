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

Node* lca(Node *n1,Node *n2,Node *node){

	if(node==NULL) return NULL;

	if(node==n1 || node==n2) return node;

	Node* left = lca(n1,n2,node->left);
	Node* right = lca(n1,n2,node->right);

	if(left==NULL) return right;

	else if(right==NULL) return left;

	else return node;

}


int main(){

	// build the tree
	Node *node  = new Node(1);
	node->left = new Node(-20);
	node->right = new Node(7);
	node->left->left = new Node(-10);
	node->left->right = new Node(6);
	node->left->left->left = new Node(7);
	int a,b;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	vector<int> v1,v2;
	RootToNode(node,a,v1);
	RootToNode(node,b,v2);
	int l1 = v1.size();
	int l2 = v2.size();
	int ans=-1;
	for(int i=0;i<min(l1,l2);i++){
		if(v1[i]!=v2[i]) break;
		ans=v1[i];
	}

	cout<<ans<<endl;

	return 0;
}
