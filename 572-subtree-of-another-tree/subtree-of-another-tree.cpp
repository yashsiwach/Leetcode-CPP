class Solution {
public:
    bool isEqual(TreeNode* root, TreeNode* sub) {
        if (!root && !sub) {
            return true;
        }
        if (!root || !sub) {
            return false;
        }
        return (root->val == sub->val) && isEqual(root->left, sub->left) && isEqual(root->right, sub->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (isEqual(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
