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

node* mergeLinkedList(node*l1,node*l2)
{
	node* first = l1,*second = l2;
	if(l1==NULL)
	{
		return l2;
	}

	if(l2==NULL)
	{
		return l1;
	}

	node* newHead;
	if(first->data<=second->data)
	{
		newHead = first;
		first = first->next;
	}
	else
	{
		newHead = second;
		second = second->next;
	}
	node* temp = newHead;

	while(first!=NULL && second!=NULL)
	{	
		if(first->data<=second->data)
		{
			temp->next = first;
			temp = temp->next;
			first = first->next;
		}
		else
		{
			temp->next = second;
			temp = temp->next;
			second = second->next;
		}
	}

	if(first==NULL && second!=NULL)
	{
		temp->next = second;
	}
	if(second==NULL && first!=NULL)
	{
		temp->next = first;
	}

	return newHead;
	
}

int main()
{
	node* head = createNode(1);
	head->next = createNode(3);
	head->next->next = createNode(5);
	head->next->next->next = createNode(7);
	// head->next->next->next->next = createNode(9);
	printLinkList(head);
	node* head2 = createNode(2);
	head2->next = createNode(4);
	head2->next->next = createNode(6);
	head2->next->next->next = createNode(8);
	head2->next->next->next->next = createNode(10);
	printLinkList(head2);

	head = mergeLinkedList(head,head2);
	printLinkList(head);
}
