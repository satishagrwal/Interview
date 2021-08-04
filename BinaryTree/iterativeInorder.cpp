#include <bits/stdc++.h> 
  
using namespace std; 
struct Node
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  

struct Node* newNode(int data) 
{ 
    struct Node* node = new struct Node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return (node); 
} 


void iterativeInorder(Node* root) 
{ 
    Node* curr = root;
    stack<Node *> s;

  	while (curr != NULL || s.empty() ==  false)
    {
		   while(curr != NULL)
		  {
		    	s.push(curr);
			    curr = curr->left;
	   	}
		
		curr = s.top();
		s.pop();	
			 
	    cout << curr->data << " ";
		curr = curr->right;
	}
} 

int main() 
{ 
    /* Constructed binary tree is 
            10 
          /   \ 
        8      2 
      /  \    / 
    3     5  2 
  */
    struct Node* root = newNode(10); 
    root->left = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->left = newNode(2); 
    iterativeInorder(root); 
    return 0; 
} 
