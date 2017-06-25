//Using single scan and two pointers. The second pointer starts moving after the first pointer has made 
//'m' moves
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* createNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
}

int nthNodeFromEnd(node* head,int m)
{
	node* fastPtr= head;
	node* slowPtr=head;
	int moves = 1;
	while(fastPtr->next!=NULL)
	{
		if(moves<m)
		{
			fastPtr = fastPtr->next;
			// cout<<"I am fast"<<fastPtr<<endl;
			moves++;
		}
		else
		{
			fastPtr = fastPtr->next;
			slowPtr = slowPtr->next;
			// cout<<"I am fast"<<fastPtr<<"I am slow"<<slowPtr<<endl;
			moves++;
		}

	}

	return slowPtr->data;
}


int main()
{
	node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	cout<<nthNodeFromEnd(head,5)<<endl;
}
