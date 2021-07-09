/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:

Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.
*/


typedef struct Node
{
	int data;
	struct Node* next;
}Node;

struct Node* reverse(struct Node* head)
{ 
	struct Node* prev = NULL;
	struct Node* curr = head;

  while (curr)
  {
		struct Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node* reverseBetween(Node* head, int m, int n)
{
	if (m == n)
		return head;

	//1)  revs and revend is start and end respectively of the portion of the linked list which
	// need to be reversed. 
  // 2) revs_prev is previous of starting position and revend_next is next of end of list to be reversed.
	Node* revs = NULL, *revs_prev = NULL;
	Node* revend = NULL, *revend_next = NULL;

	// Find values of above pointers.
	int i = 1;
	Node* curr = head;
	while (curr && i <= n) 
  {
		if (i < m)
    {
			revs_prev = curr;
    }
    
		if (i == m)
    {
			revs = curr;
    }
    
		if (i == n)
    {
			revend = curr;
			revend_next = curr->next;
		}

		curr = curr->next;
		i++;
	}
  
  // Delink from end of n
	revend->next = NULL;

	// Reverse linked list starting with revs.
	revend = reverse(revs);

	// If starting position was not head
	if (revs_prev)
  {
		revs_prev->next = revend;
  }
	// If starting position was head
	else
  {
		head = revend;
  }
  
  // Connect last left over list's node
	revs->next = revend_next;
	return head;
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

int main()
{
	struct Node* head = NULL;
	push(&head, 70);
	push(&head, 60);
	push(&head, 50);
	push(&head, 40);
	push(&head, 30);
	push(&head, 20);
	push(&head, 10);
	reverseBetween(head, 3, 6);
	print(head);
	return 0;
}
