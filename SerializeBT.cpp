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




void InorderTraversal(Node *node){

	if(node==NULL) return;

	InorderTraversal(node->left);
	cout<<node->data<<" ";
	InorderTraversal(node->right);

}

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
	string str;
	while(!q.empty()){

		Node *cur = q.front();
		q.pop();

		if(cur==NULL) str+="#,";

		else str+=(to_string(cur->data)+",");

		if(cur!=NULL){
			q.push(cur->left);
			q.push(cur->right);
		}

	}

	cout<<str<<endl;
	stringstream ss(str);
	string token;
	vector<string> result;
	while (getline(ss, token, ',')) {
        result.push_back(token);
    }

    queue<Node*> q2;
    int idx=0;
    q2.push(new Node(stoi(result[idx])));
    idx++;

    while(!q2.empty()){

    	Node *cur = q2.front();
    	q2.pop();
    	if(idx>=result.size()) break;
    	string s = result[idx];
    	if(s=="#"){
    		cur->left=NULL;
    	}
    	else{
    		cur->left = new Node(stoi(result[idx]));
    		q2.push(cur->left);
    	}
    	idx++;
    	if(idx>=result.size()) break;
    	s = result[idx];
    	if(s=="#"){
    		cur->right=NULL;
    	}
    	else{
    		cur->right = new Node(stoi(result[idx]));
    		q2.push(cur->right);
    	}

    	idx++;

    }

	
	return 0;
}
