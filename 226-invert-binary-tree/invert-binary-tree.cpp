// class Solution {
// public:
//     void solve(TreeNode* left, TreeNode* right) {
//         if (left == nullptr || right == nullptr) {
//             return;
//         }
        
//         // Swap the values of the nodes
//         swap(left->val, right->val);
        
//         // Recursively invert the subtrees
//         solve(left->left, right->right);
//         solve(left->right, right->left);
//     }
    
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == nullptr) {
//             return nullptr;
//         }
        
//         // Start the recursive inversion
//         solve(root->left, root->right);
        
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Swap the left and right subtrees
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        
        return root;
    }
};
