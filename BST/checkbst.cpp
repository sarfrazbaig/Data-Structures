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

int findMax(node* mynode)
{
	node* current = mynode;
	while(current->right!=NULL)
	{
		current = current->right;
	}

	return current->data;
}

int findMin(node* mynode)
{
	node* current = mynode;
	while(current->left!=NULL)
	{
		current = current->left;
	}

	return current->data;
}



int isBST(node*root)
{
	//If root is NULL then it is a BST
	if(root==NULL)
	{
		return 1;
	}

	if(root->left!=NULL && findMax(root)>root->data)
	{
		return 0;
	}

	else if(root->right!=NULL && findMin(root)<root->data)
	{
		return 0;
	}

	if(!isBST(root->left) || !isBST(root->right))
	{
		return 0;
	}

	return 1;
}

int main()
{
	node* root = createNode(6);
	root->left = createNode(2);
	root->right = createNode(8);
	root->left->left = createNode(1);
	root->left->right = createNode(5);
	

	cout<<isBST(root)<<endl;
}

