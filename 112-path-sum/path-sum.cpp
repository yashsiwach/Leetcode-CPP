class Solution {
public:
    bool solve(TreeNode* root, int targetSum, int s) {
        if (root == nullptr) {
            return false;
        }
        
        s += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return s == targetSum;
        }

        bool l = solve(root->left, targetSum, s);
        bool r = solve(root->right, targetSum, s);
        return l || r;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int s = 0;
        return solve(root, targetSum, s);
    }
};
