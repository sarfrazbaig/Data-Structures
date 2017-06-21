#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

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

node* createNode(int data)
{
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
}


int findIntersection(node *head1,node* head2)
{
	stack<node*>s1,s2;
	while(head1!=NULL)
	{
		s1.push(head1);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		s2.push(head2);
		head2 = head2->next;
	}

	node* current=NULL;
	while(s1.top()==s2.top())
	{
		current = s1.top();
		s1.pop();
		s2.pop();
	}

	return current->data;


}


int main()
{
	node* head = createNode(1);
	head->next = createNode(3);
	head->next->next = createNode(5);
	head->next->next->next = createNode(7);
	head->next->next->next->next = createNode(9);

	node* head2 = createNode(2);
	head2->next = createNode(4);
	head2->next->next = createNode(6);
	head2->next->next = head->next->next;
	printLinkList(head);
	printLinkList(head2);
	cout<<findIntersection(head,head2)<<endl;



}

