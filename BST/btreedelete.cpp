
//Review this code later
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

node* minValue(node* mynode)
{
	node* current = mynode;
	while(current->left!=NULL)
	{
		current = current->left;
	}

	return current;
}


//If it has no child delete it normally
//If it has one child copy the child to the node and delete the child
//If it has two children then replace the node with its inorder successor and then delete the inorder succesor
node* deleteTree(node* root,int key)
{
	if(root==NULL)
	{
		return root;
	}

	if(root->data>key)
	{
		root->left = deleteTree(root->left,key);
	}

	else if(root->data<key)
	{
		root->right = deleteTree(root->right,key);
	}
	else
	{
		if(root->left==NULL)
		{
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}

		node* temp = minValue(root->right);
		root->data = temp->data;
		root->right = deleteTree(root->right,temp->data);

	}

	return root;

}

void preorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
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

	deleteTree(root,3);
	preorder(root);
}

