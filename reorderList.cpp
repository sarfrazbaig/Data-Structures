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

node* findMiddle(node*head)
{
	node* slowPtr = head;
	node* fastPtr = head;

	int i=0;
	while(fastPtr->next!=NULL)
	{
		if(i==0)
		{
			fastPtr = fastPtr->next;
			i=1;
		}
		else
		{
			fastPtr = fastPtr->next;
			slowPtr = slowPtr->next;
			i=0;
		}
	}

	return slowPtr->next;
}

node* reverse(node* head)
{

}



node* reOrderList(node* head)
{

}

int main()
{
	node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	printLinkList(head);


}

