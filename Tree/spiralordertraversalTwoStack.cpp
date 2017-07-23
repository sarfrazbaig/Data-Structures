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


void spiralOrderTraversal(node* root)
{
	stack<node*> s1,s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			node* temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->left)
			{
				s2.push(temp->left);
			}
			if(temp->right)
			{
				s2.push(temp->right);
			}
		}

		while(!s2.empty())
		{
			node* temp = s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->right)
			{
				s1.push(temp->right);
			}
			if(temp->left)
			{
				s1.push(temp->left);
			}
		}
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

	spiralOrderTraversal(root);
}

