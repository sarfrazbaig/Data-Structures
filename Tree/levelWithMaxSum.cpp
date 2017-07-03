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

int maxLevelSum(node*root)
{
	if(root==NULL)
	{
		return 0;
	}

	queue<node*>q;
	q.push(root);
	q.push(NULL);
	int maxSum = INT_MIN;
	node* temp;
	int current_sum = 0;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp==NULL)
		{
			if(current_sum>maxSum)
			{
				maxSum = current_sum;

			}
			current_sum = 0;
			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			current_sum+=temp->data;
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

	return maxSum;
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
	cout<<maxLevelSum(root)<<endl;
}

