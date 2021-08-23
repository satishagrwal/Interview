#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	Node* left;
	Node* right;
	int hd;
	int data;
};

Node* newNode(int key)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

void topview(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	map<int, int> m;
	int hd = 0;
	root->hd = hd;

	q.push(root);

	cout << "The top view of the tree is : \n";

	while (q.size())
  {	
      Node *temp = q.front();
      hd = temp->hd;
      q.pop();

		if (m.count(hd) == 0)
    {
			m[hd] = temp->data;
    }
    
		if (temp->left)
    {
      temp->left->hd = hd - 1;
			q.push(root->left);
		}
    
		if (temp->right)
    {
			temp->right->hd = hd + 1;
			q.push(temp->right);
		}

	}

	for (auto i = m.begin(); i != m.end(); i++)
  {
		cout << i->second << " ";
	}
}

int main()
{
	/* Create following Binary Tree
			1
		/ \
		2 3
		\
			4
			\
			5
			\
				6*/
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->left->right->right = newNode(5);
	root->left->right->right->right = newNode(6);
	cout << "Following are nodes in top view of Binary "
			"Tree\n";
	topview(root);
	return 0;
}
