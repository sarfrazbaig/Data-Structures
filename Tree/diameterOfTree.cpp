#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

int height(node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	return (max(height(root->left),height(root->right)))+1;
}

int diameter(node*root)
{
	if(root==NULL)
	{
		return 0;
	}

	int lDiameter = diameter(root->left);
	int rdiameter = diameter(root->right);

	int lheight = height(root->left);
	int rHeight = height(root->right);

	return (max(lheight+rHeight+1, max(lDiameter,rdiameter)));
}






node* createNode(int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
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

	cout<<diameter(root)<<endl;
}

