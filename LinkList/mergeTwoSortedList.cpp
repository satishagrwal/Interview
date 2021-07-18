#include <bits/stdc++.h> 
using namespace std; 
  
struct Node
{ 
    int data; 
    struct Node* next; 
}; 
  
// Function to create newNode in a linkedlist 
Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
//function to print linked list 
void printList(Node* node,int array[]) 
{ 
    int index = 0;
    
    while (node != NULL)
    { 
        array[index++] = node->data; 
        node = node->next; 
    } 
} 
  
// Merges two given lists in-place. This function 
// mainly compares head nodes and calls merge() 
Node* merge(Node* list1, Node* list2) 
{ 
    if (!list1)
    {
        return list2;
    }
    
    if (!list2)
    {
        return list1; 
    }
    
    // start with the linked list 
    // whose head data is the least 
    if (list1->data < list2->data)
    { 
        list1->next = merge(list1->next, list2); 
        return list1; 
    } 
    else
    { 
        list2->next = merge(list1, list2->next); 
        return list2; 
    } 
} 
  

int main() 
{ 
    int array[6];
    Node* head1 = newNode(2); 
    head1->next = newNode(4); 
    head1->next->next = newNode(6); 
  
    // 2->4->6 LinkedList created 
  
    Node* head2 = newNode(1); 
    head2->next = newNode(3); 
    head2->next->next = newNode(4); 
  
    // 1->3->4 LinkedList created 
  
    Node* mergedhead = merge(head1, head2); 
  
    printList(mergedhead,array);
    
    for(int i=0;i<sizeof(array)/sizeof(array[0]);i++)
    {
        cout<<array[i];
    }
    return 0; 
} 


/* Try more Inputs
Case 1:
  Node* head1 = newNode(1); 
  head1->next = newNode(4); 
 
  Node* head2 = newNode(2); 
  head2->next = newNode(5); 
  Node* mergedhead = merge(head1, head2); 
 list1.printList(list1.head,result);
 expected = [1,2,4,5]
 
 Case 2:
  Node* head1 = newNode(1); 
 
  Node* head2 = newNode(2); 
  head2->next = newNode(5); 
  Node* mergedhead = merge(head1, head2); 
 list1.printList(list1.head,result);
 expected = [1,2,5]
*/
