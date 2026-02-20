class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int size = que.size();
            bool x_found = false;
            bool y_found = false;

            for(int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();

                // 1. Check if the current node is the parent of BOTH x and y
                // If they are siblings, they cannot be cousins.
                if(curr->left && curr->right) {
                   if((curr->left->val == x && curr->right->val == y) ||
                      (curr->left->val == y && curr->right->val == x)) {
                        return false; 
                    }
                }

                // 2. Mark if x or y is found at THIS level
                if(curr->val == x) x_found = true;
                if(curr->val == y) y_found = true;
                
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            } 

            // 3. After checking the whole level:
            // If both were found on the same level (and didn't trigger the sibling check), they are cousins!
            if(x_found && y_found) return true;

            // 4. If only one was found on this level, they are at different depths.
            if(x_found || y_found) return false;
        }
        return false;
    }
};
