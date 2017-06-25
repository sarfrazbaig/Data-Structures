#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head = NULL;

void printStack()
{
	node* temp = head;
	if(temp==NULL)
	{
		cout<<"Stackk is empty"<<endl;
	}
	else
	{
		cout<<"Current status of stack"<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}	
	}
	
}

bool isEmpty()
{
	return head==NULL?true:false;
}

void push(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;

	if(head==NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	printStack();
}

void pop()
{
	node* temp = head;
	head = head->next;

	free(temp);
	printStack();
}

int top()
{
	if(head==NULL)
	{
		cout<<"Stack is empty"<<endl;
		return 0;
	}
	else
	{
		return head->data;
	}
}







int main()
{
	cout<<isEmpty()<<endl;
	for(int i=1;i<=5;i++)
	{
		push(i);
	}
	cout<<isEmpty()<<endl;

	pop();
	push(6);
	cout<<top()<<endl;
	
}