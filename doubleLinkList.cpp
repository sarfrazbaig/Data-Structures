#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};


node* insertFirst(node* head,int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(head==NULL)
	{
		head = newNode;
	}
	else
	{
		 newNode->next = head;
		 head->prev = newNode;
		 head = newNode;
	}

	return head;

}

node* insertMiddle(node* head,int data,int pos)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	node* temp1 = head;
	node* temp2 = head;

	for(int i=1;i<=pos-1;i++)
	{
		temp1= temp1->next;
	}
	for(int i=1;i<=pos-2;i++)
	{
		temp2 = temp2->next;
	}

	newNode->next = temp1;
	newNode->prev = temp2;
	temp2->next = newNode;
	temp1->prev = newNode;

	return head;
}

node* insertLast(node* head,int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	node* temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;

	return head;
}

node* deleteFirst(node* head)
{
	node* temp = head;
	head = head->next;
	head->prev = NULL;

	free(temp);

	return head;
}

node* deleteLast(node* head)
{
	node* temp = head,*temp2 = NULL;
	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}
	temp2= temp->next;
	temp->next = NULL;
	free(temp2);

	return head;
}

node* deletePos(node* head,int pos)
{
	node* temp = head;
	for(int i=1;i<=pos-1;i++)
	{
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	free(temp);

	return head;
}


void printLinkList(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}

	cout<<endl;

}

int main()
{
	node* head=NULL;
	head=insertFirst(head,1);
	head=insertFirst(head,2);
	head=insertFirst(head,3);
	// cout<<head<<endl;
	head=insertFirst(head,4);
	head=insertFirst(head,5);
	head = insertMiddle(head,100,2);
	head = insertLast(head,8);
	printLinkList(head);
	// head = deleteFirst(head);
	// head = deleteLast(head);
	head = deletePos(head,3);

	printLinkList(head);	


}