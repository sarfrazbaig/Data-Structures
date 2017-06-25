#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	int height;
};

//Function to get height of a tree
int height(node* root)
{
	if(root==NULL)
		return 0;
	else
		return root->height;
}







int main()
{
	
}