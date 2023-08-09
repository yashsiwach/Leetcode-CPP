class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftCount = countNodes(root->left);   // Count nodes in the left subtree
        int rightCount = countNodes(root->right); // Count nodes in the right subtree
        
        return leftCount + rightCount + 1; // Count the current node as well
    }
};
