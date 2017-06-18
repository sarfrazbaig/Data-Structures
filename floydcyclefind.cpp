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


bool hasCycle(node* head)
{
	node* fastPtr=head,*slowPtr=head;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	node* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	//Comment out this line to check if linklist has loop
	head->next->next->next->next = head->next->next;
	cout<<hasCycle(head)<<endl;

}
