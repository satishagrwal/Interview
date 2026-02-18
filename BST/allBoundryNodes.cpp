#include<bits/stdc++.h>  
using namespace std;

struct node { 
    int data; 
    struct node *left, *right; 
}; 
  

void printLeftNodes(struct node* root)
{
     if( !root || ( !root->left && !root->right ) )
     return;
     
     std::cout << root->data << std::endl;
     
     if( root->left )
     {
       printLeftNodes(root->left); 
     }
     else{
        printLeftNodes(root->right);
     }
}
 
void printRightNodes(struct node* root)
{
     if( !root || ( !root->left && !root->right ) )
     return;
     
     if( root->right )
     {
       printRightNodes(root->right); 
     }
     else{
        printRightNodes(root->left);
     }
     
     std::cout << root->data << std::endl;
}

void printLeafNodes(struct node* root)
{
    if (!root) return;
    printLeafNodes(root->left);
    if( !root->left && !root->right )
    {
        std::cout << root->data << std::endl;
    }
    printLeafNodes(root->right);
}
// A function to do boundary traversal of a given binary tree 
void printBoundaryNodes(struct node* root) 
{ 
     std::cout << root->data << std::endl;
     
     printLeftNodes(root->left);
     printLeafNodes(root->left);
     printRightNodes(root->right);
} 
  

struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  

int main() 
{ 
   
    struct node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(14); 
    root->left->right = newNode(16); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(17); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 
  
    printBoundaryNodes(root); 
  
    return 0; 
}

/* Try more Inputs
Case1: 
struct node* root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = nnewNode(6);
root->right->right = newNode(7);
root->left->left->left = newNode(8);
root->left->left->right = newNode(9);
root->left->right->right = new Node(10);
root->right->right->left = new Node(11);
root->left->left->right->left = new Node(12);
root->left->left->right->right = new Node(13);
root->right->right->left->left = new Node(14);
printLeftView(root)
expected = [1,2,4,8,12,13,10,6,14,11,7,3]
*/
