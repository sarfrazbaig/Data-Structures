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

int findIntersection(node*head1,node*head2)
{
	int l1=0,l2=0,dif=0;
	node*head_one = head1,*head_two = head2;

	while(head_one!=NULL)
	{
		l1++;
		head_one = head_one->next;
	}

	while(head_two!=NULL)
	{
		l2++;
		head_two = head_two->next;
	}

	if(l1>l2)
	{
		head_one = head1;
		head_two = head2;
		dif = l1-l2;
	}
	else
	{
		head_one = head2;
		head_two = head1;
		dif = l2-l1;
	}

	for(int i=0;i<dif;i++)
	{
		head_one = head_one->next;
	}

	while(head_one!=NULL && head_two!=NULL)
	{
		if(head_one==head_two)
		{
			return head_one->data;
		}
		head_one = head_one->next;
		head_two = head_two->next;
	}

	return 0;


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
