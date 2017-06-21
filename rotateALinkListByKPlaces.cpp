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


void printLinkList(node* head)
{
	while(head!=NULL)
	{
		if(head->next!=NULL)
		{
			cout<<head->data<<"->";
		}
		else
		{
			cout<<head->data<<"->NULL";
		}
		head = head->next;
	}
	cout<<endl;
}

node* nthNodeFromEnd(node* head,int m)
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

	return slowPtr;
}


node* rotateList(node* head,int k)
{

	node* temp = head;
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}

	k = k % count;
	node* newHead = nthNodeFromEnd(head,k);
	cout<<newHead->data<<endl;
	node* temp2 = head;
	while(temp2->next!=newHead)
	{
		temp2 = temp2->next;
	}
	temp2->next = NULL;

	node*temp3 = newHead;
	while(temp3->next!=NULL)
	{
		temp3 = temp3->next;
	}

	temp3->next = head;
	head = newHead;

	return head;

}

int main()
{
	node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	printLinkList(head);
	head = rotateList(head,1);
	printLinkList(head);

}
