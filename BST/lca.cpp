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

int leastCommonAncestor(node* root,node* one,node* two)
{
	while(1)
	{
		//If the value of current root is in between one and two that means it is the LCA
		if(root->data>one->data && root->data<two->data || root->data>two->data && root->data<one->data)
		{
			return root->data;
			break;
		}

		if(root->data>one->data)
		{
			root=root->left;
		}
		else
		{
			root=root->right;
		}
	}
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

	cout<<leastCommonAncestor(root,root->right->right,root->right->left)<<endl;
}

