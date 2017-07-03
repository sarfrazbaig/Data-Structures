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

void preorder(node* root)
{
	stack <node*>s;
	while(1)
	{
		while(root)
		{
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}

		if(s.empty())
		{
			break;
		}
		root = s.top();
		s.pop();
		root = root->right;
	}
	cout<<endl;
}

void inorder(node* root)
{
	stack<node*>s;
	while(1)
	{
		while(root)
		{
			s.push(root);
			root = root->left;
		}
		if(s.empty())
		{
			break;
		}
		root = s.top();
		s.pop();
		cout<<root->data<<" ";
		root = root->right;

	}
	cout<<endl;
}

void postorder(node*root)
{
	stack<node*>s;
	node* prev = NULL;

	do
	{
		while(root!=NULL)
		{
			s.push(root);
			root = root->left;
		}

		while(root==NULL && !s.empty())
		{
			root = s.top();
			if(root->right==NULL || root->right==prev)
			{
				cout<<root->data<<" ";
				s.pop();
				prev = root;
				root = NULL;
			}
			else
			{
				root = root->right;
			}

		}

	}while(!s.empty());

	cout<<endl;
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

	preorder(root);
	inorder(root);
	postorder(root);
}

