/*
Given a binary tree, return the Iterative  preorder traversal of its nodes' values
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};


void printPreOrderIteratively(Node *root)
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

Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


int main()
{
	Node *root = newNode(6);
	root->left = newNode(4);
	root->right = newNode(10);
	root->left->right = newNode(5);
	root->right->left = newNode(8);
	root->right->right = newNode(12);

	cout << "PreOrder traversal of binary tree is \n";
	printPreOrderIteratively(root);
	return 0;
}
