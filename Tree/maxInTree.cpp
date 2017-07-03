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

int maxInTree(node*root)
{

	int maximum=INT_MIN,left,right;
	if(root!=NULL)
	{
		left = maxInTree(root->left);
		right = maxInTree(root->right);
		return max(root->data,max(left,right));
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
	cout<<maxInTree(root)<<endl;
}

