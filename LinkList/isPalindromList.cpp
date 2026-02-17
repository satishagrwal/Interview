/*
Given a singly linked list, determine if its a palindrome. 
Return 1 or 0 denoting if its a palindrome or not, respectively.
Notes: 
- Expected solution is linear in time and constant in space.
For example,
List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/

#include <iostream>

using namespace std;

struct Node
{
	char data;
	struct Node* next;
};


void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next;
  
	while (current != NULL) 
  {
		next = current->next;
		current->next = prev;
    
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

bool compare(struct Node* head1, struct Node* head2)
{
	struct Node* temp1 = head1;
	struct Node* temp2 = head2;

	while (temp1 && temp2)
  {
		  if (temp1->data != temp2->data)
      {
		    return 0;
      }
    	temp1 = temp1->next;
			temp2 = temp2->next;
	}

	if (temp1 == NULL && temp2 == NULL)
  {
		return 1;
  }
	/* Will reach here when one is NULL
	and other is not */
	return 0;
}

  /*
  bool isPalindrome(struct Node* head)
  {
    if (!head || !head->next)
    {
        return true;
    }
    
    stack<int> s;
    Node* slow = head, *fast = head;
    
    while (fast && fast->next)
    {
        s.push(slow->data);
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (fast)
    {
       slow = slow->next;
    }
    
    while (s.size() && slow)
    {
        if (s.top() != slow->data)
        {
            return false;
        }
        s.pop();
        slow = slow->next;
    }
    return true;
 }
  */

bool isPalindrome(struct Node* head)
{
	struct Node *slow_ptr = head; 
  struct *fast_ptr = head;
  
	struct Node *second_half;
  struct *prev_of_slow_ptr = head;
  
  // To handle odd size list
	struct Node* midnode = NULL;
  
	bool res = true; 

	if (head != NULL && head->next != NULL)
  {
		 while (fast_ptr != NULL && fast_ptr->next != NULL)
     {
		  	fast_ptr = fast_ptr->next->next;  
			  prev_of_slow_ptr = slow_ptr;
			  slow_ptr = slow_ptr->next;
		}

		/* fast_ptr would become NULL when there are even elements in list.
		And not NULL for odd elements. We need to skip the middle node
		for odd case and store it somewhere so that we can restore the
		original list*/
		if (fast_ptr != NULL)
    {
			midnode = slow_ptr;
			slow_ptr = slow_ptr->next;
		}

		// Now reverse the second half and compare it with first half
		second_half = slow_ptr;
    
    // NULL terminate first half
		prev_of_slow_ptr->next = NULL; 
    
		reverse(&second_half);
    
     // compare
		res = compare(head, second_half);

		/* Construct the original list back */
		reverse(&second_half);

		// If there was a mid node (odd size case) which
		// was not part of either first half or second half.
		if (midnode != NULL)
    {
			prev_of_slow_ptr->next = midnode;
			midnode->next = second_half;
		}
		else
    {
			prev_of_slow_ptr->next = second_half;
    }
	}
	return res;
}

void push(struct Node** head_ref, char new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(struct Node* ptr)
{
	while (ptr != NULL) 
  {
		printf("%c->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

/*
  ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
        {
          return head;
        }
         ListNode* curr = head;
         ListNode* prev = nullptr, *next = nullptr;
         while(curr != nullptr)
         {
             next = curr->next;
             curr->next = prev;
             
             //update pointers
             prev = curr;
             curr = next;
         }
         return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
        {
           return true;
        }
        
        ListNode *slow = head, *fast = head;
        
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *secondHalf = reverseList(slow);
        ListNode *firstHalf = head;
        
        ListNode *copySecondHalf = secondHalf;
        
        bool res = true;
        
        while(secondHalf)
        {
            if(firstHalf->val != secondHalf->val)
            {
                res = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        reverseList(copySecondHalf);
        return res;
    }
*/
int main()
{
	struct Node* head = NULL;
	char str[] = "abccba";
	int i;

	for (i = 0; str[i] != '\0'; i++) 
  {
		push(&head, str[i]);
		printList(head);
		isPalindrome(head) ? printf("Is Palindrome\n\n") : printf("Not Palindrome\n\n");
	}

	return 0;
}
