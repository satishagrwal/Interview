#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node *next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		cout<<"the given previous node cannot be NULL";
		return;
	}

	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
  
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
  {
		last = last->next;
  }
	
	last->next = new_node;
	return;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

bool searchData(Node* node, int data)
{
    while(node != NULL)
    {
        if(node->data == data )
        {
            return true;
        }
        node = node->next;
    }
}

void deleteNode(Node** head, int data)
{
     Node* current = *head;
     Node* prev = NULL;
     
     if(current != NULL && current->data == data)
     {
        *head = current->next;
        delete current;
        return;
     }
     
     while(current != NULL && current->data != data)
     {
         prev = current;
         current = current->next;
     }
     
     if(current == NULL)
     return;
          
     prev->next = current->next;
     delete current;
}

void deleteNodeAtPosition(Node **head_ref, int position)
{
	if (*head_ref == NULL)
	{
		return;
	}
	
	Node* current = *head_ref;

	if (position == 0)
	{
	    *head_ref = current->next;
		free(current);			
		return;
	}

	for(int i = 0; current != NULL && i < position - 1; i++)
	{
		current = current->next;
	}
	
	if (current == NULL || current->next == NULL)
	{
		return;
	}
	
	Node *next = current->next->next;

	delete current->next;
	
	current->next = next;
}

void deleteList(Node **head_ref)
{
    Node* current = *head_ref;
    Node* next = NULL;
    
    while(current != NULL)
    {
       next = current->next;
       delete current;
       
       current = next;
    }
    
    *head_ref = NULL;
}

int main()
{
	Node* head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	append(&head, 10);
	insertAfter(head->next, 8);
	
	cout<<"Created Linked list is: ";
	printList(head);
	
	cout<<"\n"<<endl;
	
	if(searchData(head, 7))
	{
	    cout<<"Data found"<<endl;
	}
	else
	{
	    cout<<"Data not found\n"<<endl;
	}
	
	deleteNode(&head, 6);
	
	cout<<"New Linked list is: ";
	printList(head);
	
	cout<<"\n"<<endl;
	
	deleteNodeAtPosition(&head, 3);
	
	cout<<"New Linked list is: ";
	printList(head);
    
    cout<<"\n"<<endl;
    cout<<"Delete Linked list\n";
    deleteList(&head);
    
    cout<<"Pushed data in Linked list is: ";
    push(&head, 7);
    printList(head);
    
	return 0;
}

