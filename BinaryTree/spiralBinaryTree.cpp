/*
[Spiral Order means  all nodes present at level 1 should be printed first from left to right,
followed by nodes of level 2 right to left, followed by nodes of level 3 from left to right and so on]
[Space O(n) due to the use stack] 

Input :        1
	          /     \
           2        3
         /  \      /  \
        7    6    5    4
       
Output : 1 2 3 4 5 6 7
*/

#include <iostream> 
#include <stack> 
using namespace std; 
  

struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 
  
void spiralBinaryTree(struct node* root) 
{ 
    stack<node*> s1;
    stack<node*> s2;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            node* node1 = s1.top();
            s1.pop();
            cout<<node1->data<<" ";
            
            if(node1->right !=NULL)
            {
                s2.push(node1->right);
            }
            
            if(node1->left !=NULL)
            {
                s2.push(node1->left); 
            }
        }
    

        while(!s2.empty())
        {
            node* node2 = s2.top();
            s2.pop();
            cout<<node2->data<<" ";
            
            if(node2->left !=NULL)
            {
                s1.push(node2->left); 
            }
            
            if(node2->right !=NULL)
            {
                s1.push(node2->right);
            }
        }
    }
} 
  
struct node* newNode(int data) 
{ 
    struct node* node = new struct node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  
int main() 
{ 
    struct node* root = newNode(2); 
    root->left = newNode(3); 
    root->right = newNode(4); 
    root->left->left = newNode(8); 
    root->left->right = newNode(7); 
    root->right->left = newNode(6); 
    root->right->right = newNode(5); 
    cout << "Spiral Order traversal of binary tree is \n"; 
    spiralBinaryTree(root); 
  
    return 0; 
} 

/* Try more Inputs
root = None
root = Node(1)  
root.left = Node(2)  
root.right = Node(3)  
actual = spiralBinaryTree(root)
expected = [1, 2, 3]

root = Node(1);
root.left = Node(2);
root.right = Node(10);
root.left.left = Node(-1);
root.left.right = Node(-4);
root.right.left = Node(-5);
root.right.right = Node(-6);
actual = spiralBinaryTree(root)
expected = [1, 2, 10, -6, -5, -4, -1]
*/
