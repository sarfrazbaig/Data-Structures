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

int leavesOfTree(node*root)
{
	if(root==NULL)
		return 0;
	int leaves = 0;
	node* temp;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if(temp->left==NULL && temp->right==NULL)
		{
			leaves++;
		}

		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}

	return leaves;
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

	cout<<leavesOfTree(root)<<endl;
}

