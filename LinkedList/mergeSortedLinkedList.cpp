//Recursive version
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

node* mergeLinkList(node*a,node*b)
{
	if(a==NULL)
	{
		return b;
	}

	if(b==NULL)
	{
		return a;
	}
	node* result;
	if(a->data<=b->data)
	{
		result = a;
		result->next = mergeLinkList(a->next,b);
	}
	else if(a->data>=b->data)
	{
		result = b;
		result->next = mergeLinkList(b->next,a);
	}

	return result;
}


int main()
{
	node* head = createNode(1);
	head->next = createNode(3);
	head->next->next = createNode(5);
	head->next->next->next = createNode(7);
	head->next->next->next->next = createNode(9);
	printLinkList(head);
	node* head2 = createNode(2);
	head2->next = createNode(4);
	head2->next->next = createNode(6);
	head2->next->next->next = createNode(8);
	head2->next->next->next->next = createNode(10);
	printLinkList(head2);

	head = mergeLinkList(head,head2);
	printLinkList(head);







}
