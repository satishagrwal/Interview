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

struct ListNode
{
	int data;
	ListNode *prev, *next;

	ListNode(int data, ListNode* prev, ListNode* next)
	{
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};   

void print(ListNode* mid)
{
	while (mid && mid->prev) 
	{
		mid = mid->prev;
	}

	ListNode* head = mid;
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void verticalSumUsingDLL(Node* root, ListNode* head)
{
   if(!root) return;
   
   head->data = root->data + head->data;
   
    if(root->left != NULL)
    {
        if(head->prev == NULL)
        {
           head->prev = new ListNode(0, NULL, NULL); 
           head->prev->next = head; 
        }
        verticalSumUsingDLL(root->left, head->prev);
    }
   
    if(root->right != NULL)
    {
       if(head->next == NULL)
       {
         head->next = new ListNode(0, NULL, NULL); 
         head->next->prev = head; 
       }
       verticalSumUsingDLL(root->right, head->next);
   }
}

int main()
{
	/* Construct below tree
                 1
		/   \
               /     \
	      2	      3
		    /   \
		   /	  \
		  5	   6
		/   \
	       /     \
	      7       8
	*/

        ListNode* headList = new ListNode(0, NULL, NULL); 
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	verticalSumUsingDLL(root, headList);
        print(headList);
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
verticalSumUsingDLL(root)
expected = [4, 2, 12, 3, 7]
*/
