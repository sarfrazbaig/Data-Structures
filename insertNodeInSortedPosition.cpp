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

node* insertNode(node*head,int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;

	node* current = head,*temp;
	while(current!=NULL && current->data<newNode->data)
	{
		temp = current;
		current = current->next;
	}
	newNode->next = current;
	temp->next = newNode;

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
			cout<<temp->data<<"->NULL";
		}
		temp = temp->next;
	}
	cout<<endl;
}


int main()
{
	node* head = createNode(1);
	head->next = createNode(3);
	head->next->next = createNode(4);
	head->next->next->next = createNode(5);
	head->next->next->next->next = createNode(6);
	insertNode(head,2);
	printLinkList(head);


}
