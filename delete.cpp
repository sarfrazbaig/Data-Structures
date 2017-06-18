#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* deleteLastNode(node* head)
{
	node* temp = head;
	node* temp2;

	while(temp->next->next!=NULL)
	{
		temp = temp->next;
	}

	temp2 = temp->next;
	temp->next = NULL;
	free(temp2);

	return head;
}

void printLinkList(node*head)
{
	node* temp = head;
	while(temp!=NULL)
	{
		if(temp->next!=NULL)
			cout<<temp->data<<"->";
		else
		{
			cout<<temp->data<<"NULL";
		}
		temp = temp->next;
	}
}



node* createNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
}

int main()
{
	node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	printLinkList(head);
	deleteLastNode(head);
	cout<<endl;
	printLinkList(head);

}

