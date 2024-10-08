#include<iostream>
#include<limits.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

class info {
public:
	int maxi;
	int mini;
	bool isBST;
	int size;
};

info solve(Node* root, int &ans){
	// base case
	if(root == NULL){
		return {INT_MIN, INT_MAX, true, 0};
	}

	info left = solve(root->left, ans);
	info right = solve(root->right, ans);

	info currNode;

	currNode.size = left.size + right.size + 1;
	currNode.maxi = max(root->data, right.maxi);
	currNode.mini = min(root->data, left.mini);

	if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
		currNode.isBST = true;
	}
	else{
		currNode.isBST = false;
	}

	// answer update
	if(currNode.isBST){
		ans = max(ans, currNode.size);
	}
	return currNode;
}


int largestBST(Node* root){
	int maxSize = 0;
	info temp = solve(root, maxSize);
	return maxSize;
}

int main(){
	Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << "Size of the largest BST is " << largestBST(root) << endl;
}