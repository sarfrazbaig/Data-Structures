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

node* insertNewNode(node*root, int data)
{
	node* temp = createNode(data);

	if(root==NULL)
	{
		return temp;
	}
	else
	{
		if(data<root->data)
		{
			root->left = insertNewNode(root->left,data);
		}
		else if(data>root->data)
		{
			root->right = insertNewNode(root->right,data);
		}
	}

	return root;
}


void preorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}



int main()
{
	node* root = createNode(2);
	root->left = createNode(1);
	root->right = createNode(3);

	insertNewNode(root,4);
	preorder(root);
}