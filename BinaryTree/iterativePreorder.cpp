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

void iterativePreorder(Node* root) 
{ 
   	if (root == NULL) 
	{
	   return;
	}

    stack<Node *> s;

	s.push(root);

	while (!s.empty())
	{
		Node *node = s.top();
		cout << node->data << " ";
		s.pop();
       
		if (node->right != NULL)
			s.push(node->right);
      
		if (node->left != NULL)
			s.push(node->left);
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
    iterativePreorder(root); 
    return 0; 
} 
