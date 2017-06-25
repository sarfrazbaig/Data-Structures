#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

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



node* createNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
}


int middleOfLinkedList(node* head)
{
	node* fastPtr=head,*slowPtr=head;
	// fastPtr = fastPtr->next;www
	int i=0;


	while(fastPtr->next!=NULL)
	{
		if(i==0)
		{
			fastPtr = fastPtr->next;
			i=1;
		}
		else if(i==1)
		{
			fastPtr = fastPtr->next;
			slowPtr = slowPtr->next;
			i=0;
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
	// head->next->next->next->next->next = createNode(6);
	cout<<middleOfLinkedList(head)<<endl;

}
