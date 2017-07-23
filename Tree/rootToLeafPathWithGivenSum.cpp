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

bool hasPath(node*root,int sum)
{
	if(root==NULL)
	{
		return 0;
	}

	if(root->left==NULL && root->right==NULL && root->data==sum)
	{
		return 1;
	}

	return hasPath(root->left,sum-root->data) || hasPath(root->right,sum-root->data);
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

	cout<<hasPath(root,71)<<endl;
}

