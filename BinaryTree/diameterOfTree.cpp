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

int calculateHeight(Node* root, int &ans){
        if(!root)
        return 0;
        
       int leftHeight = calculateHeight(root->left, ans);
       int rightHeight = calculateHeight(root->right, ans);

       ans = max(ans, leftHeight + rightHeight);
       
       return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(Node* root) {
      if(!root)
        return 0;
     
     int diameter = 0;

     calculateHeight(root, diameter);

     return diameter;
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
	cout << "The diameter of the tree is " << diameterOfBinaryTree(root);

	return 0;
}
