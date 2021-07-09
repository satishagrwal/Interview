/*
A sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* deleteDuplicates(struct Node* head)
{
    if(!head || !head->next)
    {
        return head;
    }
    
    struct Node* tmpHead = (struct Node*) malloc(sizeof(struct Node));
    tmpHead->next = head;
    struct Node* prev = tmpHead;
    
    while (head)
    {
        while (head->next && head->data == head->next->data)
        {
            head = head->next;
        }
        
        if (prev->next == head)
        {
            prev = prev->next;
        }
        else
        {
            prev->next = head->next;
        }   
        head = head->next;
    }
    return tmpHead->next;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);	
	(*head_ref) = new_node;
}

void printList(struct Node *node)
{
	while (node!=NULL)
	{
	  printf("%d ", node->data);
	  node = node->next;
	}
}

int main()
{
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 13);
	push(&head, 13);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);
	push(&head, 10);

	printf("\n Linked list before duplicate delete ");
	printList(head);

	/* Remove duplicates from linked list */
	head = deleteDuplicates(head);

	printf("\n Linked list after duplicate delete ");		
	printList(head);		

	return 0;
}
