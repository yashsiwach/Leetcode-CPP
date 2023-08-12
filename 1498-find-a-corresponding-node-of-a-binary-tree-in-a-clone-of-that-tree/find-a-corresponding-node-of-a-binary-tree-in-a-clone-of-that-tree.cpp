class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!cloned) {
            return nullptr;
        }
        
        if (original == target) {
            return cloned;
        }
        
        TreeNode* leftResult = getTargetCopy(original->left, cloned->left, target);
        TreeNode* rightResult = getTargetCopy(original->right, cloned->right, target);
        
        return leftResult ? leftResult : rightResult;
    }
};
