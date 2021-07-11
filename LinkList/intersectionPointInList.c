/*
Find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Time complexity : O( m + n ) 
Auxiliary Space:  O(1)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node* next;
};


int getIntesectionNode(struct Node* head1, struct Node* head2)
{
    if(head1 == NULL || head2 == NULL)
    {
        return 0;
    }
    
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    
    while(temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
            
        if(temp1 == temp2)
        {
            return temp1->data;
        }
        
        if(!temp1)
        {
            temp1 = head2;
        }
        
        if(!temp2)
        {
            temp2 = head1;
        }
    }
    
    return temp1->data;
}

int main()
{
	/*
	Create two linked lists

	1st 3->6->9->15->30
	2nd 10->15->30

	15 is the intersection point
*/

	struct Node* newNode;
	struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
	head1->data = 10;

	struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
	head2->data = 3;

	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 6;
	head2->next = newNode;

	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	printf("\n The node of intersection is %d \n",
		getIntesectionNode(head1, head2));

	getchar();
}
