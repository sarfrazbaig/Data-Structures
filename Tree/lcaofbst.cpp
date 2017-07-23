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

int lcaOfNodes(node* root,node* node1,node* node2)
{
	if(root->data > max(node1->data,node2->data))
	{
		return lcaOfNodes(root->left,node1,node2);
	}
	else if(root->data < min(node1->data,node2->data) )
	{
		return lcaOfNodes(root->right,node1,node2);
	}
	else 
		return root->data;
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

	cout<<lcaOfNodes(root,root->left->left,root->right->right);
}

