/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,

Given 1->4->3->2->5->2 and x = 3,

return 1->2->2->4->3->5.
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void partition(struct Node **head_ref, int x)
{
	Node *lessStart = NULL;
	Node *lessEnd = NULL;

	Node *greaterStart = NULL;
	Node *greaterEnd = NULL;
.
	Node *currNode = *head_ref;
	
	while(currNode != NULL)
  {
		if(currNode -> data < x) 
    {
			if(lessStart == NULL)
      {
				lessStart = currNode;
				lessEnd = lessStart;
			}
			else
      {
				lessEnd -> next = currNode;
				lessEnd = lessEnd -> next;
			}
		}
		else
    {
			if(greaterStart == NULL)
      {
				greaterStart = currNode;
				greaterEnd = greaterStart;
			}
			else
      {
				greaterEnd -> next = currNode;
				greaterEnd = greaterEnd -> next;
			}
		}
		currNode = currNode -> next;
	}

	if(lessStart == NULL || greaterStart == NULL)
  {
		return;
	}
	
	lessEnd -> next = greaterStart;
	greaterEnd -> next = NULL;
	
	// Modify head pointer to
	// starting of less list.
	*head_ref = lessStart;
}


void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

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
	  push(&head, 2);
    push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 1);

	printf("\nOriginal Linked list \n");
	printList(head);

	partition(&head, 3);

	printf("\nModified Linked list \n");
	printList(head);

	return 0;
}
