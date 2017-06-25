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

node* BuildBST(int a[],int left,int right)
{
	node* temp;
	int mid;
	if(left>right)
	{
		return NULL;
	}

	
	mid = (left+right)/2;
	temp = createNode(a[mid]);
	temp->left = BuildBST(a,left,mid-1);
	temp->right=BuildBST(a,mid+1,right);
	

	return temp;
}

void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}



int main()
{
	int a[6] = {1,2,3,4,5,6};
	node* root = BuildBST(a,0,5);
	inorder(root);
	
}

