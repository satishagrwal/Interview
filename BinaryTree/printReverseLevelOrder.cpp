/*
Algorithm to print Binary Tree nodes level by level in reverse order.
It means all the nodes at the last level should be printed first followed
by the nodes of second last level and so on in Time Complexity O(n) and 
Space Complexity O(n).

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};


void printReverseLevelOrder(Node *root)
{
	if (root == NULL) return;

	queue<Node *> q;
    stack<Node *> s;

	q.push(root);

	while (q.empty() == false)
	{
		Node *node = q.front();
		q.pop();
        s.push(node);
      
		if (node->right != NULL)
			q.push(node->right);
      
		if (node->left != NULL)
			q.push(node->left);
	}
  
   while(!s.empty())
   {
     Node *node = s.top();
     cout << node->data << " ";
     s.pop();
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
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << " Reverse Level Order traversal of binary tree is \n";
	printReverseLevelOrder(root);
	return 0;
}
