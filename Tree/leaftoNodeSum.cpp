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


vector<int> path;

bool leafToNodeSumPath(node* root,int sum)
{
	if(root==NULL)
	{
		return false;
	}

	if(root->left==NULL && root->right==NULL)
	{
		if(root->data==sum)
		{
			path.push_back(root->data);
			return true;
		}
		else
		{
			return false;
		}
	}

	if(leafToNodeSumPath(root->left,sum-root->data))
	{
		path.push_back(root->data);
		return true;
	}

	if(leafToNodeSumPath(root->right,sum-root->data))
	{
		path.push_back(root->data);
		return true;
	}

	return false;
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


	cout<<leafToNodeSumPath(root,100)<<endl;
}

