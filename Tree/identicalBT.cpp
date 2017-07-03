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

bool structurallyIdentical(node*root1,node*root2)
{
	if(root1==NULL && root2==NULL)
	{
		return 1;
	}

	if(root1==NULL || root2==NULL)
	{
		return 0;
	}

	return (root1->data==root2->data && structurallyIdentical(root1->left,root2->left) && structurallyIdentical(root1->right,root2->right));

}

int main()
{
	node* root1 = createNode(1);
	root1->left = createNode(2);
	root1->right = createNode(3);
	root1->left->left = createNode(4);
	root1->left->right = createNode(5);
	root1->right->left = createNode(6);
	root1->right->right = createNode(7);

	node* root2 = createNode(1);
	root2->left = createNode(2);
	root2->right = createNode(3);
	root2->left->left = createNode(4);
	root2->left->right = createNode(5);
	root2->right->left = createNode(6);
	// root2->right->right = createNode(7);

	cout<<structurallyIdentical(root1,root2)<<endl;
}

