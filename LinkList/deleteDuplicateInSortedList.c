/* Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void deleteDuplicates(struct Node* head)
{
	if(head == NULL)
	return;
	
	Node* current = head;
	Node* Next = NULL;

	while(current->next != NULL)
	{
	    if(current->data == current->next->data)
	    {
	        Next = current->next->next;
	        free(current->next);
	        
	        current->next = Next;
	    }
	    else
	    {
	       current = current->next;
	    }
	}
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

	/*linked list will be 11->11->11->13->13->20 */
	push(&head, 20);
	push(&head, 13);
	push(&head, 13);
	push(&head, 11);
	push(&head, 11);
	push(&head, 11);								

	printf("\n Linked list before duplicate removal ");
	printList(head);

	deleteDuplicates(head);

	printf("\n Linked list after duplicate removal ");		
	printList(head);		

	return 0;
}
