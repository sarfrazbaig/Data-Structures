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


int LCA(node*root,node*a,node*b)
{
	if(root==NULL)
	{
		return -1;
	}

	if(root==a ||root==b)
	{
		return root->data;
	}

	int left = LCA(root->left,a,b);
	int right = LCA(root->right,a,b);

	if(left!=-1 && right!=-1)
	{
		return root->data;
	}

	if(left==-1)
	{
		return right;
	}
	else if(right==-1)
	{
		return left;
	}
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

	cout<<LCA(root,root->left->left,root->left->right)<<endl;
}

