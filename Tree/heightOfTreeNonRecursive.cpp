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

int heightOfTree(node* root)
{
	if(root ==NULL)
	{
		return 0;
	}
	int level = 0;
	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if(temp==NULL)
		{
			
			if(!q.empty())
				q.push(NULL);
			level++;
		}
		else
		{
			if(temp->left)
			{
				q.push(temp->left);
			}

			if(temp->right)
			{
				q.push(temp->right);
			}
		}
	}

	return level;
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
	cout<<heightOfTree(root)<<endl;
}

