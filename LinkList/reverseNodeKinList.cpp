/*

Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
    Node* next;
}Node;



Node* reverse(Node* head, int n)
{
	if (!head)
		return NULL;
		
    Node* curr = head, *prev = NULL, *next = NULL;
	int i = 0;
	
  while (curr && i < n) 
  {
     next = curr->next;
     curr->next = prev;
     
     prev= curr;
     curr = next;
     i++;
  }
  
  if(next != NULL)
  {
    head->next = reverse(next, n);
  }
  
  return prev;
}

void print(struct Node* head)
{
	while (head != NULL)
    {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main(void)
{
    struct Node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);          
 
     printf("\nGiven linked list \n");
     print(head);
     head = reverse(head, 3);
 
     printf("\nReversed Linked list \n");
     print(head);
 
     return(0);
}
