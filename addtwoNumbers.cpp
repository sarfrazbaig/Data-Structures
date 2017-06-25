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

node* insert(node* head,int data)
{	
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;

	node* temp2 = head;
	while(temp2->next!=NULL)
	{
		temp2 = temp2->next;
	}

	temp2->next = temp;

	return head;
}



node* addLinkLists(node* head1,node* head2)
{
	if(head1==NULL)
	{
		return head2;
	}
	if(head2==NULL)
	{
		return head1;
	}

	node* temp1= head1,*temp2 = head2;
	int length1=0,length2=0;
	while(temp1!=NULL)
	{
		length1++;
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		length2++;
		temp2= temp2->next;
	}
	node* temp3=head1,*temp4 = head2;
	if(length1>=length2)
	{
		for(int i=1;i<=length2 && temp3!=NULL && temp4!=NULL;i++)
		{
			temp3->data = temp3->data+temp4->data;
			temp3 = temp3->next;
			temp4 = temp4->next;
		}

		node*temp6 = head1;
		int carry = 0;
		while(temp6!=NULL)
		{
			temp6->data = temp6->data+carry;
			if(temp6->data>=10)
			{
				temp6->data = temp6->data-10;
				carry = 1;
			}
			temp6 = temp6->next;
		}
		if(carry>0)
		{
			head1 = insert(head1,carry);
		}
	
		return head1;

	}
	else if(length2>=length2)
	{
		for(int i=1;i<=length1 && temp3!=NULL && temp4!=NULL;i++)
		{
			temp4->data = temp4->data+temp3->data;
			temp3 = temp3->next;
			temp4 = temp4->next;
		}

		node*temp6 = head2;
		int carry = 0;
		while(temp6!=NULL)
		{
			temp6->data = temp6->data+carry;
			if(temp6->data>=10)
			{
				temp6->data = temp6->data-10;
				carry = 1;
			}
			temp6 = temp6->next;
		}
		if(carry>0)
		{
			head2 = insert(head2,carry);
		}

		return head2;
	}



}

int main()
{
	node* head1 = createNode(9);
	head1->next = createNode(9);
	// head1->next->next = createNode(1);
	// head1->next->next->next = createNode(4);
	// head1->next->next->next->next = createNode(5);

	// printLinkList(head1);

	node* head = createNode(1);
	// head->next = createNode(4);
	// head->next->next = createNode(3);
	// head->next->next->next = createNode(4);
	// head->next->next->next->next = createNode(5);

	// printLinkList(head);

	node* result = addLinkLists(head,head1);
	printLinkList(result);


}
