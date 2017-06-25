#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head;


node* createNode(int data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next =NULL;
}


void traverse(node* head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp= temp->next;
	}
}	

void reverse(node* p)
{
	if(p->next==NULL)
	{
		head = p;
		return;
	}
	reverse(p->next);
	node* q = p->next;
	q->next = p;
	p->next = NULL;
}



int main()
{
	head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);

	traverse(head);
	cout<<endl;
	reverse(head);
	traverse(head);
}