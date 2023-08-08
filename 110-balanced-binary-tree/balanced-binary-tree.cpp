class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        int m = max(l, r) + 1;
        return m;
    }
    
    bool solve(TreeNode* l, TreeNode* r) {
        if (abs(height(l) - height(r)) > 1) {
            return false;
        }
        
        if (l != nullptr && r != nullptr) {
            return solve(l->left, l->right) && solve(r->left, r->right);
        }
        
        return true;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        return solve(root->left, root->right);
    }
};
