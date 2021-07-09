#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
	}
};


Node* findLCA(Node* root, Node* node1, Node* node2)
{
   if(root == NULL)
   {
      return NULL;
   }
   
   if(root->data == node1->data || root->data == node2->data)
    {
        return root;
    }
    
    Node* Left = findLCA(root->left, node1, node2);
    Node* Right = findLCA(root->right, node1, node2);
    
    if(Left !=NULL && Right !=NULL)
    {
       return root;    
    }
    
    return (Left != NULL)? Left: Right;
}

int main()
{
    Node* root = nullptr;
    /* Construct below tree
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
           / \
          7   8
    */

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->right->right = new Node(8);

    cout<<findLCA(root, root->right->left->left, root->right->right)->data<<endl;
    cout<<findLCA(root, root->right->left->left, new Node(10))->data<<endl;
    cout<<findLCA(root, root->right->left->left, root->right->left->left)->data<<endl;
    cout<<findLCA(root, root->right->left->left, root->right->left)->data<<endl;
    cout<<findLCA(root, root->left, root->right->left)->data<<endl;

    return 0;
}
