#include <iostream>
using namespace std;
 
// A BST node
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
 
// Recursive function to insert an key into BST
Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

 
// Function to find k'th largest element in BST
void printKthSmallest(Node* root, int k, int &count)
{
    if (root == nullptr || count >= k) {
        return;
    }

   printKthSmallest(root->left, k, count);
   
    if (count < k) {
        count++;
        if (count == k) {
            std::cout << root->data << std::endl;
            return;
        }
    };
   
   if (count < k) {
     printKthSmallest(root->right, k, count);
   }
}
 
// main function
int main()
{
    Node* root = NULL;
    int keys[] = { 5, 3, 6, 2, 4, 1 };
    int counter = 0;
    for (int x : keys)
        root = insert(root, x);
 
    int k = 5;
    printKthSmallest(root, k, counter);
    return 0;
}


/* Try more Inputs

case1:
keys = [13, 14, 22, 25, 23, 32, 26,28,40]
root = insert(root, key)
actual = printKthSmallest(root,3)
expected = 22

case2:
keys = [5,3,6,2,4,1]
root = insert(root, key)
actual = printKthSmallest(root,3)
expected = 3

*/
