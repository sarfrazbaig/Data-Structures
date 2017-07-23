#include <bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
};


void printPath(node* root);
void printArray(int path[],int n);
void printPathrecurse(node* root,int path[],int len);


node* createNode(int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void printPath(node* root)
{
	int path[1000];
	printPathrecurse(root,path,0);
}

void printPathrecurse(node* root,int path[],int len)
{
	if(root==NULL)
	{
		return;
	}

	path[len] = root->data;
	len++;

	if(root->left==NULL && root->right==NULL)
	{
		printArray(path,len);
	}
	else
	{
		printPathrecurse(root->left,path,len);
		printPathrecurse(root->right,path,len);
	}
}

void printArray(int path[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<path[i]<<" ";
	}
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

	printPath(root);
}

