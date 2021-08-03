#include<bits/stdc++.h>
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

void print(map<int, int> &Map)
{
    map <int, int>:: iterator it;
   
    for (it = Map.begin(); it != Map.end(); ++it)
    {
        cout << it->first << ": "<< it->second << endl;
    }
}

void verticalSum(Node* root, int disFromCent, map<int, int> &Map)
{
   if(!root) return;
   
    verticalSum(root->left, disFromCent-1, Map);
   
    Map[disFromCent] += root->data;
   
    verticalSum(root->right, disFromCent+1, Map);
}

int main()
{
	/* Construct below tree
		  1
		/   \
	   /	 \
	  2	      3
			/   \
		   /	 \
		  5	     6
		/   \
	   /	 \
	  7	     8
	*/

    map<int, int> Map;
    
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	verticalSum(root, 0, Map);
    print(Map);
	return 0;
}

/* Try more Inputs
TreeNode root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);
root.right.right = new TreeNode(7);
verticalSum(root)
expected = [4, 2, 12, 3, 7]
*/
