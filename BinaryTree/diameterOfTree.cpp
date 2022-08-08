/*
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
Find diameter of tree in Time Complexity O(n).

Input:
           1
	      /     \
      2         3
     /       /   \
    7      6      4
         /   \      \      
       17     9       8
                \
                 19
               
Output: 7
*/

#include <iostream>
using namespace std;


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


int height(Node* root)
{
    if(!root)
    return 0;
    
    return 1 + max(height(root->left), height(root->right));
}


int findDiameter(Node* root)
{
     if(!root)
     return 0;
     
     int leftHeight = height(root->left);
     int rightHeight = height(root->right);
     
     int diameter = 1 + leftHeight + rightHeight;
     
     int lDiameter = findDiameter(root->left);
     int rDiameter = findDiameter(root->right);
     
     
	 return max(max(lDiameter, rDiameter), diameter);
}

int main()
{
	Node* root = nullptr;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(7);
	root->right->left = new Node(6);
	root->right->left->left = new Node(17);
	root->right->right = new Node(4);
	root->right->right->right = new Node(8);
	root->right->left->right = new Node(9);
    root->right->left->right->right = new Node(19);
	cout << "The diameter of the tree is " << findDiameter(root);

	return 0;
}
