#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* createNode(int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int maxInBinaryTree(node*root)
{
	int root_val,left,right,maxVal = INT_MIN;
	if(root!=NULL)
	{
		root_val = root->data;
		left = maxInBinaryTree(root->left);
		right = maxInBinaryTree(root->right);

		maxVal = max(root_val,max(left,right));
	}

	return maxVal;

}

int main()
{
	node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	cout<<maxInBinaryTree(root)<<endl;
}

