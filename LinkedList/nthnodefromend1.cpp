
//Need two scans to find the result
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

int nthNodeFromEnd(node* head,int m)
{
	node* temp = head;
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}	

	int p = count-m+1;
	node* temp2 = head;
	for(int i=1;i<=p-1;i++)
	{
		temp2 = temp2->next;
	} 

	return temp2->data;
}

int main()
{
	node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	cout<<nthNodeFromEnd(head,3)<<endl;

}
