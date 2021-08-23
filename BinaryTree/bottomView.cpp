#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	int dis;
	Node *left, *right;

	Node(int key)
	{
		data = key;
		dis = INT_MAX;
		left = right = NULL;
	}
};


void bottomView(Node *root)
{
	if (root == NULL)
		return;

	int d = 0;

	// TreeMap which stores key value pair
	// key is horizontal distance from central and its value
	map<int, int> m;
	queue<Node *> q;

	root->dis = d;
	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
    
		d = temp->dis;

    // Every time we find a node having same horizontal
		// distance we need to replace the data in the map.
		m[d] = temp->data;

		if (temp->left != NULL)
		{
			temp->left->dis = (d-1);
			q.push(temp->left);
		}

		if (temp->right != NULL)
		{
			temp->right->dis = (d+1);
			q.push(temp->right);
		}
	}

	for (auto i = m.begin(); i != m.end(); ++i)
  {
		cout << i->second << " ";
  }
}

int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n"
	bottomView(root);
	return 0;
}

