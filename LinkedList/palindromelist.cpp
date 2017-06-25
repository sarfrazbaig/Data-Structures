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


node* middle(node* head)
{
	node* fast = head,*slow = head;
	int i=0;
	int count = 0;
	while(fast->next!=NULL){
	if(i==0)
	{
		count++;
		fast = fast->next;
		i=1;
	}
	else if(i==1)
	{
		count++;
		fast = fast->next;
		slow = slow->next;
		i=0;
	}
	}
	return slow->next;
}

node* reverse(node* head,node*head1)
{
	if(head->next==NULL)
	{
		return head;
	}
	node* haha=head;
	while(haha->next!=head1)
	{
		haha = haha->next;
	}
	node* prev = NULL;
	node* current = head1;
	node* next;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head1 = prev;
	haha->next = head1;

	return head;
	
}

int isPalindrome(node* head)
{
	node* middleNode = middle(head);
	head = reverse(head,middleNode);
	middleNode = middle(head);
	// printLinkList(head);
	node* temp = head;
	// cout<<middleNode->data<<" "<<temp->data<<endl;
	int flag = 0;
	while(middleNode!=NULL)
	{
		// cout<<middleNode->data<<" "<<temp->data<<endl;
		if(temp->data==middleNode->data)
		{
			temp = temp->next;
			middleNode = middleNode->next;
			flag=1;
		}
		else
		{
			flag = 0;
			break;
		}
		
	}
	return flag;
}




int main()
{
	node* head = createNode(1);
	head->next = createNode(1);
	// head->next->next = createNode(1);
	// head->next->next->next = createNode(1);
	// head->next->next->next->next = createNode(1);
	// head->next->next->next->next->next = createNode(1);
	cout<<isPalindrome(head)<<endl;
}
