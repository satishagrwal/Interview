class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        // DFS
        if (root->left) {
            // Check if the left child is a LEAF
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            } else {
                // If not a leaf, keep searching deeper in the left subtree
                sum += sumOfLeftLeaves(root->left);
            }
        }
        
        // Always check the right subtree for potential left leaves
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
