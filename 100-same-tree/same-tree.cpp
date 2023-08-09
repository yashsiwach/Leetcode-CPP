class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true; // Both trees are empty, they're the same
        }
        
        if (p == nullptr || q == nullptr) {
            return false; // One tree is empty, the other is not
        }
        
        if (p->val != q->val) {
            return false; // Values of nodes are not equal
        }
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
