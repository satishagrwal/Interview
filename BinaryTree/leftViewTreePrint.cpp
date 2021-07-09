#include <bits/stdc++.h> 
using namespace std; 
  
class node 
{ 
  public: 
    int data; 
    node *left, *right; 
}; 
   
node* newNode(int item) 
{ 
    node* temp = new node(); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Recursive function to print left view of a binary tree. 
void leftViewPrint(node* root, int level, int* max_level) 
{ 
   if(root == NULL)
      return;
      
    if(*max_level < level)
    {
        cout<<root->data<<endl;
        *max_level = level;
    }
    leftViewPrint(root->left, level+1, max_level);
    leftViewPrint(root->right, level+1, max_level);
} 
   
void leftView(node* root) 
{ 
  int max_level = 0;
  leftViewPrint(root, 1, &max_level);
} 
  

int main() 
{ 
    node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 
  
    leftView(root); 
  
    return 0; 
} 

/* Try more Inputs
Case 1:
BinaryTree tree = new BinaryTree();
tree.root = new Node(12);
tree.root.left = new Node(10);
tree.root.right = new Node(30);
tree.root.right.left = new Node(25);
tree.root.right.right = new Node(40);
printLeftView(root)
expected = [12,10,25]

Case2: 
BinaryTree root = newNode(10);
root.left = newNode(12);
root.right = newNode(3);
root.left.right = newNode(4);
root.right.left = newNode(5);
root.right.left.right = newNode(6);
root.right.left.right.left = newNode(18);
root.right.left.right.right = newNode(7);
printLeftView(root)
expected = [10,12,4,6,18]
*/
