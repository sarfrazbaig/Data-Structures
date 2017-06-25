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


node* reverseLinkListRecursive(node*head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	else
	{
		node* result = reverseLinkListRecursive(head->next);
		head->next->next = head;
		head->next = NULL;
		return result;
	}
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

int main()
{
	node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	printLinkList(head);
	head = reverseLinkListRecursive(head);
	printLinkList(head);


}
