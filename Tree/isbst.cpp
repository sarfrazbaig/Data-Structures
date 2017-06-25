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

bool isTheTreeBST(node* root,int left_range,int right_range)
{
	if(root==NULL)
	{
		return 1;
	}

	if(!root->data>=left_range && !root->data<=right_range)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	return isTheTreeBST(root->left,left_range,root->data) && isTheTreeBST(root->right,root->data,right_range);
}


int main()
{
	node* root = createNode(7);
	root->left = createNode(3);
	root->right = createNode(6);
	root->left->left = createNode(1);
	root->left->right = createNode(2);
	root->right->left = createNode(4);
	root->right->right = createNode(5);

	cout<<isTheTreeBST(root,INT_MIN,INT_MAX)<<endl;
}

