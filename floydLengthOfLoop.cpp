//Check for errors
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

int findLengthOfLoop(node* head)
{
	node* fastPtr = head,*slowPtr = head;
	int loopExists = 0;
	int length = 0;
	while(slowPtr && fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr==fastPtr)
		{
			loopExists = 1;
			break;
		}
	}

	if(loopExists)
	{
		fastPtr= fastPtr->next;
		while(slowPtr!=fastPtr)
		{			
			fastPtr = fastPtr->next;
			length++;
		}

		return length;
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
	head->next->next->next->next = head->next;
	cout<<findLengthOfLoop(head)<<endl;


}
