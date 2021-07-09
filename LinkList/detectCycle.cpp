// C++ program to return first node of loop.

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Solving using constant space.
Example :
Input : 
                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4
Return the node corresponding to node 3. 

*/

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	int data;
	struct Node* next;
};

/*
Node* detectCycle(Node* A)
{
	unordered_set<Node*> set;

	Node *ptr = A;

	// Default consider that no cycle is present
	while (ptr != NULL) 
  {
		if (set.find(ptr) != set.end())
    {
		  return ptr;
    }
		else
    {
			set.insert(ptr);
		}
		ptr = ptr->next;
	}
	return NULL;
}
*/

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL)
  {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* detectLoop(Node* head)
{
	// If list is empty or has only one node
	// without loop
	if (head == NULL || head->next == NULL)
  {
		return NULL;
  }
  
	Node *slow = head;
  Node *fast = head;

	while (fast && fast->next)
  {
    slow = slow->next;
		fast = fast->next->next; 
    if (slow == fast)
    {
		 	break;
    }
	}

	// If loop does not exist
	if (slow != fast)
  {
		return NULL;
  }
  
	// If loop exists. Start slow from
	// head and fast from meeting point.
	slow = head;
	while (slow != fast)
  {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	/* loop for testing */
	head->next->next->next->next->next = head->next->next;

	Node* result = detectLoop(head);
  
	if (result == NULL)
  {
		cout << "Loop does not exist";
  }
	else
  {
		cout << "Loop starting node is " << result->data;
  }
	return 0;
}
