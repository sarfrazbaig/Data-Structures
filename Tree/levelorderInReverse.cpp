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

void levelOrderInReverse(node*root)
{
	queue<node*>q;
	stack<node*>s;
	q.push(root);
	while(!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if(temp->right)
		{
			q.push(temp->right);
		}

		if(temp->left)
		{
			q.push(temp->left);
		}

		s.push(temp);
	}

	while(!s.empty())
	{
		node* temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
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

	levelOrderInReverse(root);
}

