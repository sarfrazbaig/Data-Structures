#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* insertFirst(node* head,int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = newNode;
	node* current = head;
	if(head==NULL)
	{
		head = newNode;
	}
	else
	{
		while(current->next!=head)
		{
			current = current->next;
		}

		newNode->next = head;
		current->next = newNode;
		head = newNode;
	}

	return head;
}

node* insertMiddle(node* head,int data,int pos)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = newNode;

	node* temp1 = head,*temp2= head;
	for(int i=1;i<=pos-1;i++)
	{
		temp1 = temp1->next;
	}
	for(int i=1;i<=pos-2;i++)
	{
		temp2 = temp2->next;
	}

	newNode->next = temp1;
	temp2->next = newNode;

	return head;
}


node* insertLast(node* head,int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = newNode;

	node* temp = head;
	while(temp->next!=head)
	{
		temp = temp->next;
	}	

	temp->next = newNode;
	newNode->next = head;

	return head;
}


node* deleteFirstNode(node* head)
{
	node* temp = head;
	node* temp2= head;
	while(temp->next!=head)
	{
		temp = temp->next;
	}
	// temp->next = temp2->next;
	// head = temp2->next;

	// free(temp2);

	// return head;
	head = head->next;
	temp->next = head;
	free(temp2);

	return head;
} 

node* deleteLastNode(node* head)
{
	node* temp = head;
	node* temp2;
	while(temp->next->next!=head)
	{
		temp = temp->next;
	}

	temp2 = temp->next;
	temp->next = head;
	free(temp2);

	return head;

}


void printCircularLL(node*head)
{
	node* current = head;
	do
	{
		cout<<current->data<<"->";
		current = current->next;
	}while(current!=head);
}


int main()
{
	node* head = NULL;
	head = insertFirst(head,1);
	head = insertFirst(head,2);
	head = insertFirst(head,3);
	head = insertFirst(head,4);
	head = insertMiddle(head,5,2);
	head = insertLast(head,7);
	printCircularLL(head);
	cout<<endl;
	head = deleteFirstNode(head);
	head = deleteLastNode(head);

	printCircularLL(head);
	
}