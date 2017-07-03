//Wrong algortihm..will correct later
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


node* deleteNode(node*root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	node* target,*temp;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp->data==data)
		{
			target = temp;
		}
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}

	swap(temp->data,target->data);
	// free(temp);

	return root;
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
	root = deleteNode(root,4);
	preorder(root);
}

